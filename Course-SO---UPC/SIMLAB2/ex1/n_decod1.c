#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int *alrm;
void func(int signal) {
    if (signal == SIGALRM) *alrm = 1;
}
int main(int argc, char *argv[]) {

    sigset_t mask;
    struct sigaction trat;
    trat.sa_handler = func;
    sigfillset(&mask);
    sigdelset(&mask, SIGCHLD);
    sigdelset(&mask, SIGALRM);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    sigaction(SIGCHLD, &trat, NULL);
    sigaction(SIGALRM, &trat, NULL);

    alrm = sbrk(sizeof(int));

    int count = atoi(argv[2]);
    char buff2[4];
    for (int i = 0; i < count; ++i) {
        int fd[2];
        int p = pipe(fd);

        int ret = fork();
        if (ret == 0) {
            dup2(fd[1], 1);
            close(fd[1]);
            close(fd[0]);
            sprintf(buff2, "%d", i);
            execlp("./decod", "decod", argv[1], argv[2], buff2, (char *)NULL);
        } else {
            close(fd[1]);
            alarm(5);
            while(!*alrm) {}
            *alrm = 0;

            kill(ret, SIGUSR1);
            sigsuspend(&mask);
            //waitpid(ret, NULL, WNOHANG);

            char c;
            char fileBuff[256];
            sprintf(fileBuff, "%s%d.txt", argv[3], i);
            int fdW = open(fileBuff, O_WRONLY | O_CREAT | O_TRUNC, 0666);

            while(read(fd[0], &c, 1) > 0) {
                write(fdW, &c, 1);
            }
            close(fdW);
        }
    }
    sbrk(-sizeof(int));
}