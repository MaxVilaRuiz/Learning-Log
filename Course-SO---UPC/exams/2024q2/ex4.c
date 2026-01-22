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
    int count = 0;
    char* p = malloc(1);
    while(getcmd(buf, sizeof(buf)) >= 0) {
        /* comanda buida */
        if (buf[0] == '\0') continue;

        // Cmd "ei"
        if (buf[0] == 'e' && buf[1] == 'i') break;

        if (buf[0] == 'h' && buf[1] == 'i') {
            char buff[MAX_BUF];
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < MAX_BUF; j++) {
                    sprintf(buff, "%c", p[MAX_BUF*i + j]);
                    write(1, buff, strlen(buff));
                }
                sprintf(buff, "\n");
                write(1, buff, strlen(buff));
            }
        }
        else {
            p = realloc(p, MAX_BUF*(count+1) * sizeof(char));
            for (int i = 0; i < MAX_BUF; i++) p[MAX_BUF*count+i] = buf[i];
            count++;

            int ret = fork();
            if (ret == 0) {
                execlp(buf, buf, NULL);
                perror("execlp");
                exit(1);
            }

            waitpid(ret, NULL, 0);
        }
    }

    free(p);

    exit(EXIT_SUCCESS);
}