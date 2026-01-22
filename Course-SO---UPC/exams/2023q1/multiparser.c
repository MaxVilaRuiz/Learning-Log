#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

void alarm_handler(int sig) {}

void Usage() {
    char buffer[32];
    sprintf(buffer, "Usage: ...\n");
    write(1, buffer, strlen(buffer));
    exit(1);
}

int main(int argc, char* argv[]) {
    sigset_t mask, wait_set;
    sigfillset(&mask);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
        perror("sigprocmask");
        exit(1);
    }

    sigfillset(&wait_set);
    sigdelset(&wait_set, SIGALRM);

    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = alarm_handler;
    if (sigaction(SIGALRM, &sa, 0) < 0) {
        perror("sigaction");
        exit(1);
    }

    int ret, fd, fd2, status;
    char c, buffer;
    for (int i = 1; i < argc; i++) {
        sprintf(buffer, "fifo_%i", i);
        if (mkfifo(buffer, 0600)) {
            perror("mkfifo");
            exit(1);
        }
        
        int p[2];
        if (pipe(p) < 0) {
            perror("pipe");
            exit(1);
        }

        ret = fork();

        if (ret == 0) {
            close(p[1]);
            sprintf(buffer, "%s.out", argv[i]);
            fd2 = open(buffer, O_CREAT | O_TRUNC | O_WRONLY, 0640);
            if (fd2 < 0) {
                perror("open");
                exit(1);
            }

            if (dup2(p[0], 0) < 0) {
                perror("dup2");
                exit(1);
            }
            close(p[0]);
            
            if (dup2(fd2, 4) < 0) {
                perror("dup2");
                exit(1);
            }
            close(fd2);

            sprintf(buffer, "fifo_%i", i);
            int fd_fifo_r = open(buffer, O_RDONLY);
            if (fd_fifo_r < 0) {
                perror("open");
                exit(1);
            }
            close(fd_fifo_r);

            sprintf(buffer, "Procés fill despert\n");
            write(1, buffer, strlen(buffer));

            execlp("./parser", "parser", NULL);
            
            perror("execlp");
            exit(1);
        }
        else if (0 < ret) {
            close(p[0]);

            alarm(1);
            sigsuspend(&wait_set);
            sprintf(buffer, "Pare despert\n");
            write(1, buffer, strlen(buffer));

            sprintf(buffer, "fifo_%i", i);
            int fd_fifo_w = open(buffer, O_WRONLY);
            if (fd_fifo_w < 0) {
                perror("open");
                exit(1);
            }
            close(fd_fifo_w);
            
            fd = open(argv[i], O_RDONLY);
            if (fd < 0) {
                perror("open");
                close(p[1]);
                waitpid(ret, NULL, 0);
                exit(1);
            }   

            while (read(fd, &c, 1) > 0) {
                write(p[1], &c, 1);
            }
            close(p[1]);
            close(fd);

            waitpid(ret, &status, 0);
            if (WIFEXITED(status)) sprintf(buffer, "El procés fill %i ha finalitzat correctament.\n", ret);
            else sprintf(buffer, "El procés fill %i no ha finalitzat correctament.\n", ret);
            write(1, buffer, strlen(buffer));
        }
        else {
            perror("fork");
            exit(1);
        }

        sprintf(buffer, "fifo_%i", i);
        unlink(buffer);
    }

    sprintf(buffer, "Final del proceso principal\n");
    write(1, buffer, strlen(buffer));

    return 0;
}