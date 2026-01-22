#include <sys/errno.h>
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

void Usage() {
    char buff[32];
    sprintf(buff, "Usage: ...\n");
    write(2, buff, strlen(buff));
    exit(1);
}

void alarm_handler(int sig) {}

int main(int argc, char* argv[]) {
    if (argc != 2) Usage();

    int p[2];
    if (pipe(p) < 0) {
        perror("pipe");
        exit(1);
    }

    sigset_t mask;
    sigfillset(&mask);
    if (sigprocmask(SIG_BLOCK, &mask, 0) < 0) {
        perror("sigprocmask");
        exit(1);
    }

    int ret = fork();
    if (ret < 0) {
        perror("fork");
        exit(1);
    }

    if (ret == 0) {
        close(p[0]);

        if (dup2(p[1], 1) < 0) {
            perror("dup2");
            exit(1);
        }
        
        execlp("./initvector", "initvector", argv[1], NULL);
        
        perror("execlp");
        exit(1);
    }

    close(p[1]);

    int n;
    if (read(p[0], &n, sizeof(int)) < 0) {
        perror("read");
        exit(1);
    }

    int* v = malloc(n * sizeof(int));
    if (v == NULL) {
        perror("malloc");
        exit(1);
    }

    if (mkfifo("MIPIPE", 0600) < 0) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(1);
        }
    }
    int fd_dummy = open("MIPIPE", O_RDONLY | O_NONBLOCK);

    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = alarm_handler;
    if (sigaction(SIGALRM, &sa, 0) < 0) {
        perror("sigaction");
        exit(1);
    }

    int c1, c2; 
    char buff[64];
    while (read(p[0], &c1, sizeof(int)) > 0) {
        read(p[0], &c2, sizeof(int));

        int ret2 = fork();
        if (ret2 < 0) {
            perror("fork");
            exit(1);
        }

        if (ret2 == 0) {
            int fd_w = open("MIPIPE", O_WRONLY);

            if (dup2(fd_w, 1) < 0) {
                perror("dup2");
                exit(1);
            }
            close(fd_w);

            sprintf(buff, "%i + %i", c1, c2);
            execlp("expr", "expr", buff, NULL);

            perror("execlp");
            exit(1);
        }

        int status;
        waitpid(ret2, &status, 0);
        if (WIFEXITED(status) && !WIFSIGNALED(status)) 
            sprintf(buff, "El proceso <%i> ha finalizado voluntariamente\n", ret2);
        else if (WIFSIGNALED(status))
            sprintf(buff, "El proceso <%i> ha finalizado involuntariamente\n", ret2);
        write(2, buff, strlen(buff));

        alarm(1);
        sigdelset(&mask, SIGALRM);
        sigsuspend(&mask);
    }

    int ret3 = fork();
    if (ret3 < 0) {
        perror("fork");
        exit(1);
    }

    if (ret3 == 0) {        
        if (dup2(fd_dummy, 0) < 0) {
            perror("dup2");
            exit(1);
        }
        close(fd_dummy);

        execlp("wc", "wc", "-l", NULL);

        perror("execlp");
        exit(1);
    }

    while (waitpid(-1, NULL, 0) > 0);
    sprintf(buff, "El proceso padre acaba\n");
    write(2, buff, strlen(buff));

    free(v);

    return 0;
}