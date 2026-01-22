#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 8

int getcmd(char *buf, int nbuf) {
    write(2, "osh# ", 5);
    memset(buf, 0, nbuf);
    ssize_t r = read(0, buf, nbuf);
    if (r < 0) return -1;
    if (r) buf[r-1] = 0; // treure el \n
    tcflush(0, TCIFLUSH); // neteja el buffer d'entrada
    return r;
}

int main() {
    char buf[MAX_BUF];
    while(getcmd(buf, sizeof(buf)) >= 0) {
        /* comanda buida */
        if (buf[0] == '\0') continue;

        // Cmd "ei"
        if (buf[0] == 'e' && buf[1] == 'i') break;

        int ret;
        if (buf[2] == '|') {
            char cmd[16];
            int p[2];
            if (pipe(p) < 0) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }

            ret = fork();
            if (ret < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (ret == 0) {
                close(p[0]);
                dup2(p[1], 1);
                close(p[1]);

                sprintf(cmd, "%c%c", buf[0], buf[1]);
                execlp(cmd, cmd, NULL);

                perror("execlp");
                exit(EXIT_FAILURE);
            }  

            ret = fork();
            if (ret < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (ret == 0) {
                close(p[1]);
                dup2(p[0], 0);
                close(p[0]);

                sprintf(cmd, "%c%c", buf[3], buf[4]);
                execlp(cmd, cmd, NULL);

                perror("execlp");
                exit(EXIT_FAILURE);
            }  

            close(p[0]);
            close(p[1]);
        }
        else {
            ret = fork();
            if (ret < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (ret == 0) {
                execlp(buf, buf, NULL);
                perror("execlp");
                exit(1);
            }
        }
        
        while (waitpid(-1, NULL, 0) > 0);
    }

    exit(EXIT_SUCCESS);
}