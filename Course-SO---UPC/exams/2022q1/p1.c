#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <signal.h>

void Usage() {
    char buff[32];
    sprintf(buff, "Usage: ...\n");
    write(1, buff, strlen(buff));
    exit(1);
}

void sigusr1_handler(int signal) {}

int main(int argc, char* argv[]) {
    if (3 < argc) Usage();

    char type;
    if (argc == 3) type = argv[2][0];
    else {
        if (strcmp(argv[0], "./p1-char.exe") == 0) type = 'c';
        else if (strcmp(argv[0], "./p1-integer.exe") == 0) type = 'i';
        else Usage();
    }

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigusr1_handler;
    if (sigaction(SIGUSR1, &sa, 0) < 0) {
        perror("sigaction");
        exit(1);
    }

    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigsuspend(&mask);

    char buff[64];
    sprintf(buff, "El proceso %i comienza\n", getpid());
    write(1, buff, strlen(buff));

    for (int i = 0; i < atoi(argv[1]); i++) {
        if (type == 'i') write(10, &i, sizeof(int));
        else {
            char c = (char)i;
            write(10, &c, sizeof(char));
        }
    }  

    sprintf(buff, "El proceso %i termina\n", getpid());
    write(1, buff, strlen(buff));
    exit(atoi(argv[1]));

    return 0;
}