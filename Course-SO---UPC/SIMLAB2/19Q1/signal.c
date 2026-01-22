#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


void handler(int signal) {
    char buff[256];
    if (signal == SIGUSR1) {
        sprintf(buff, "%d: SIGUSR1\n", getpid());
    } else if (signal == SIGALRM) {
        sprintf(buff, "%d: Timeout\n", getpid());
    }
    write(1, buff, strlen(buff));
}

int main() {

    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGALRM);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    struct sigaction trat;
    trat.sa_handler = handler;
    sigaction(SIGUSR1, &trat, NULL);
    sigaction(SIGALRM, &trat, NULL);

    alarm(5);
    sigsuspend(&mask);
}