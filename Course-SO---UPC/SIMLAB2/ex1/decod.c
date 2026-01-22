#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

void func() {}
int main(int argc, char *argv[]) {
    int i = atoi(argv[3]);
    int n = atoi(argv[2]);
    sigset_t mask;
    struct sigaction trat;
    trat.sa_handler = func;
    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    sigaction(SIGUSR1, &trat, NULL);
    sigsuspend(&mask);

    int fd = open(argv[1], O_RDONLY);
    char c;
    int count = 0;
    while(read(fd, &c, 1) > 0) {
        if (count%n == i && c != '*') {
            write(1, &c, 1);
        }
        count++;
    }
    char buff[32];
    sprintf(buff, "\n");
    write(1, buff, strlen(buff));

    close(fd);
}
