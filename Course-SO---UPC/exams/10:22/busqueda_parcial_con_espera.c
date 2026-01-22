#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>


int pid;
char buff[250];
void error_y_exit(char error[]) {
    sprintf(buff, "ERROR: %s \n", error);
    write(1, buff, strlen(buff));
    exit(2);
}



void handler(int s) {
    sprintf(buff, "SIGNAL recibido %d \n", s);
    write(1, buff, strlen(buff));
    if (s == SIGUSR1) {
       
    } else if (s == SIGUSR2) {
        if (pid != 0) kill(pid, SIGUSR2);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) error_y_exit("minArgs");

    char *palabra = argv[2];
    char *fichero = argv[3];
    pid = atoi(argv[1]);

    struct sigaction trat; 
    sigset_t mask;
    sigemptyset(&mask); 
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    trat.sa_flags=0; 
    trat.sa_handler = handler;
    if (sigaction(SIGUSR1, &trat, NULL) < 0) error_y_exit("sigaction");
    if (sigaction(SIGUSR2, &trat, NULL) < 0) error_y_exit("sigaction");
    sigprocmask(SIG_SETMASK, &mask, NULL);


    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigsuspend(&mask);


    int ret = fork();
    if (ret == 0) {
        execlp("grep", "grep", palabra, fichero, (char*)NULL);
        error_y_exit("execpl");
    } if (ret < 0) error_y_exit("fork");
    else {
    }

    int exit_code;
    waitpid(ret, &exit_code, 0);

        sprintf(buff, "Proceso finalizado: %d, con satus: %s", exit_code, WEXITSTATUS(exit_code));
        write(1, buff, strlen(buff));
    if (WIFEXITED(exit_code)) {
        if (WEXITSTATUS(exit_code) == 0) {
            if (pid != 0) kill(pid, SIGUSR1);
        } else if (WEXITSTATUS(exit_code) == 1) {
            if (pid != 0) kill(pid, SIGUSR2);
        }
        sprintf(buff, "Termina grep palabra %s fichero %s.c : exit %d", *palabra, *fichero, WEXITSTATUS(exit_code));
        write(1, buff, strlen(buff));
    }
}
