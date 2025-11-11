#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define NUM_HIJOS 5
pid_t pids[NUM_HIJOS];
int hijos_vivos = NUM_HIJOS;

void error_y_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
}

void trata_alarma(int s) 
{
    char buff[256];
    sprintf(buff, "\nPADRE: Han pasado 2 segundos. Matando a los hijos vivos...\n");
    write(1, buff, strlen(buff));

    for (int i = 0; i < NUM_HIJOS; i++) if (pids[i] > 0) kill(pids[i], SIGKILL);
}


int main(int argc, char *argv[])
{
    int res;
    char buff[256];
    struct sigaction sa;
    sigset_t mask;
	int first_time = 1;

    sa.sa_handler = &trata_alarma;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction", 1);

    for (int i = 0; i < NUM_HIJOS; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            sprintf(buff, "HIJO %d: PID=%d ejecutándose...\n", i, getpid());
            write(1, buff, strlen(buff));

            sleep(1 + i); 
            sprintf(buff, "HIJO %d: Termina normalmente\n", getpid());
            write(1, buff, strlen(buff));
            exit(10 + i);
        }
        else if (pid > 0) pids[i] = pid;
        else error_y_exit("fork", 1);
    }

    while (hijos_vivos > 0)
    {
        alarm(2);

        pid_t pid_hijo = waitpid(-1, &res, 0);

        if (pid_hijo > 0)
        {
            int restante = alarm(0); 

            sprintf(buff, "PADRE: Ha terminado el hijo %d\n", pid_hijo);
            write(1, buff, strlen(buff));

            if (WIFEXITED(res))
            {
                sprintf(buff, " - Ha terminado con exit(%d)\n", WEXITSTATUS(res));
                write(1, buff, strlen(buff));
            }
            else if (WIFSIGNALED(res))
            {
                sprintf(buff, " - Ha terminado por señal %d (%s)\n", 
                        WTERMSIG(res), strsignal(WTERMSIG(res)));
                write(1, buff, strlen(buff));
            }

            if (restante > 0 && first_time)
            {
                sprintf(buff, "PADRE: Alarma cancelada, quedaban %d segundos\n", restante);
                write(1, buff, strlen(buff));
				first_time = 0;
            }

            for (int i = 0; i < NUM_HIJOS; i++)
            {
                if (pids[i] == pid_hijo)
                {
                    pids[i] = -1;
                    break;
                }
            }

            hijos_vivos--;
        }
    }

    sprintf(buff, "PADRE: Todos los hijos han terminado.\n");
    write(1, buff, strlen(buff));
    return 0;
}