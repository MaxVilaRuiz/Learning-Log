#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[]) {
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    int count = atoi(argv[1]);
    int *ptr = sbrk(sizeof(int) * count);
    for (int i = 0; i < count; ++i) {
        int ret = fork();
        if (ret == 0) {
            execlp("./signal", "signal", (char *)NULL);
        } else {
            ptr[i] = ret;
        }
    }

    for (int i = 0; i < count; ++i) {
        int pid = ptr[i];
        kill(pid, SIGUSR1);
    }

    while(waitpid(-1, NULL, WNOHANG) > 0) {

    }
    sbrk(-(sizeof(int) * count));
}