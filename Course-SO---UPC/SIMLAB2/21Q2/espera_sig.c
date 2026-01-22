#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void handler(int signal) {
    int exitCode = 0;
    if (signal == SIGINT) exitCode = 1;
    else if (signal == SIGUSR1) exitCode = 2;
    else if (signal == SIGUSR2) exitCode = 3;

    char buff[256];
    sprintf(buff, "Se ha recivido el signal: %d\n", signal);
    write(2, buff, strlen(buff));

    if (exitCode != 0) exit(exitCode);
}

int main(int argc, char *argv[]) {
    sigset_t mask;
    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    struct sigaction trat;
    trat.sa_handler = handler;
    sigaction(SIGINT, &trat, NULL);
    sigaction(SIGUSR1, &trat, NULL);
    sigaction(SIGUSR2, &trat, NULL);

    sigdelset(&mask, SIGINT);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigsuspend(&mask);
}