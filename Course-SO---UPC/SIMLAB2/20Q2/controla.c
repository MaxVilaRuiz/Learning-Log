#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int PID, TIMELIMIT, TIME = 0;
    sigset_t mask;

void handler(int sig) {
    if (sig == SIGALRM) {
        if (TIME >= TIMELIMIT) {
            kill(PID, SIGKILL);
        } else {
                            char buff[256];
            sprintf(buff, "%d %d \n", TIME, TIMELIMIT);
            write(1, buff, strlen(buff));

            TIME++;
            alarm(1);
            sigsuspend(&mask);
        }
    }
    if (sig == SIGCHLD) {
                char buff[256];
            sprintf(buff, "FINISHED %d %d \n", TIME, TIMELIMIT);
            write(1, buff, strlen(buff));
                        //sigsuspend(&mask);

    }
    if (sig == SIGUSR1) {
        char buff[256];
        sprintf(buff, "Tiempo: %d\n", TIME);
        write(1, buff, 256);
        sigsuspend(&mask);
    }
}

void usage() {

}

int main(int argc, char *argv[]) {
    if (argc < 3) usage();
    
    TIMELIMIT = atoi(argv[1]);
    char *commandName = argv[2];

    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    int ret = fork();
    if (ret == 0) {
        execlp(commandName, commandName, (char *)NULL);
    } else {
        PID = ret;

        sigdelset(&mask, SIGALRM);
        sigdelset(&mask, SIGUSR1);
        sigdelset(&mask, SIGCHLD);

        struct sigaction trat;
        trat.sa_flags=0; 
        trat.sa_mask=mask;
        trat.sa_handler = handler;
        sigaction(SIGALRM, &trat, NULL);
        sigaction(SIGUSR1, &trat, NULL);
        sigaction(SIGCHLD, &trat, NULL);

        alarm(1);
        sigsuspend(&mask);
    }
}