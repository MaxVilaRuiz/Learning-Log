#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>



void error_y_exit(char e[]) {
}
void usage() {
}


void handler(int s) {
    if (s == SIGALRM) {
        char buff[50];
        sprintf(buff, "%d: Timeout \n", getpid());
        write(1, buff, strlen(buff));
    } else if (s == SIGUSR1) {
        int n = alarm(0);
        exit(n);
    }
}

int main(int argc, char *argv[]) {
    usage();
    int num = atoi(argv[1]);

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error_y_exit("sigprocmask");
    struct sigaction tr;
    tr.sa_handler = handler;
    tr.sa_flags = SA_RESETHAND;
    
    if (sigaction(SIGALRM, &tr, NULL) < 0) error_y_exit("sigaction");
    if (sigaction(SIGUSR1, &tr, NULL) < 0) error_y_exit("sigaction");


    int pids[num];
    for (int i = 0; i < num; ++i) {
        int ret = fork();
        if (ret == 0) {
            alarm(3);

            sigfillset(&mask);
            sigdelset(&mask, SIGALRM);
            sigdelset(&mask, SIGUSR1);
            sigsuspend(&mask);
        } else if (ret < 0) {
            error_y_exit("fork");
        } else {
            pids[i] = ret;
        }
    }

    for (int i = 0; i < num; ++i) {
        if (pids[i] %2 == 0) {
            kill(pids[i], SIGUSR1);
        }
    }

    for (int i = 0; i < num; ++i) {
        int exit_status;
        waitpid(pids[i], &exit_status, WNOHANG);
        if (pids[i] %2 == 0) {
            char buff[256];
            sprintf(buff, "Hijo %d. Segundos restantes %d \n", pids[i], WEXITSTATUS(exit_status));
            write(1, buff, strlen(buff));
        }
    }
}
