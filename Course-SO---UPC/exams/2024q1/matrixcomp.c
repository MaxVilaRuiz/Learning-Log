#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int request = 0;
int finished = 0;

void Usage() {
    char buff[32];
    sprintf(buff, "Usage: ...\n");
    write(1, buff, strlen(buff));
    exit(1);
}

void sigusr2_handler(int s) {
    request = SIGUSR2;
}

void sigusr1_handler(int s) {
    request = SIGUSR1;
}

void alrm_handler(int s) {
    finished = 1;
}

void child_handler(int s) {}

int main(int argc, char* argv[]) {
    if (argc != 2) Usage();

    sigset_t mask;
    sigemptyset(&mask);

    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = sigusr1_handler;
    sigaction(SIGUSR1, &sa, 0);
    sa.sa_handler = sigusr2_handler;
    sigaction(SIGUSR2, &sa, 0);
    sa.sa_handler = alrm_handler;
    sigaction(SIGALRM, &sa, 0);

    int ret = fork();
    if (ret == 0) {
        struct sigaction sa1;
        sa1.sa_flags = 0;
        sa1.sa_handler = child_handler;
        sigemptyset(&sa1.sa_mask);
        sigaction(SIGUSR1, &sa1, 0);

        int fd_c1 = open(argv[1], O_RDONLY);

        int j, s = 0;
        for (int i = 0; i < 5; i++) {
            lseek(fd_c1, (5*i + i) * sizeof(int), SEEK_SET);
            kill(getppid(), SIGUSR1);
            sigsuspend(&mask);
            read(fd_c1, &j, sizeof(int));
            s += j;
        }

        kill(getppid(), SIGALRM);
        exit(s);
    }

    int ret2 = fork();
    if (ret2 == 0) {
        struct sigaction sa2;
        sa2.sa_flags = 0;
        sa2.sa_handler = child_handler;
        sigemptyset(&sa2.sa_mask);
        sigaction(SIGUSR2, &sa2, 0);

        int fd_c2 = open(argv[1], O_RDONLY);

        int j2, s2 = 0;
        for (int i = 1; i < 5; i++) {
            lseek(fd_c2, 5*(4-i) + i, SEEK_SET);
            kill(getppid(), SIGUSR2);
            sigsuspend(&mask);
            read(fd_c2, &j2, sizeof(int));
            s2 += j2;
        }

        kill(getppid(), SIGALRM);
        exit(s2);
    }

    int printed = 0;
    char buff[64];
    while (printed < 2) {
        sigsuspend(&mask);

        if (request == SIGUSR1) {
            kill(ret, SIGUSR1);
            request = 0;
        }
        else if (request == SIGUSR2) {
            kill(ret2, SIGUSR2);
            request = 0;
        }

        if (finished) {
            int status;
            pid_t pid = wait(&status);
            int sum = WEXITSTATUS(status);

            sprintf(buff, "%s: PID %d with sum = %d\n", printed == 0 ? "First" : "Second", pid, sum);
            write(1, buff, strlen(buff));

            finished = 0;
            printed++;
        }
    }

    return 0;
}