#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>     
#include <signal.h>

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

void sigint_handler(int s) {
    char buff[32];
    sprintf(buff, "prompt interrumpido\n");
    write(1, buff, strlen(buff));

    sprintf(buff, "osh# ");
    write(1, buff, strlen(buff));
}

int main() {    
    sigset_t mask;
    sigemptyset(&mask);
    if (sigprocmask(SIG_SETMASK, &mask, 0) < 0) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUF];
    while(getcmd(buf, sizeof(buf)) >= 0) {
        /* comanda buida */
        if (buf[0] == '\0') continue;

        // Cmd "ei"
        if (buf[0] == 'e' && buf[1] == 'i') break;

        int ret = fork();
        if (ret == 0) {
            execlp(buf, buf, NULL);
            perror("execlp");
            exit(1);
        }

        waitpid(ret, NULL, 0);
    }

    exit(EXIT_SUCCESS);
}