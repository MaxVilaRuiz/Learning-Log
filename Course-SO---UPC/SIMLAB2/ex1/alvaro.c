#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int para = 0;

void Usage() {
    char buffer[255];
    sprintf(buffer, "Usage: argc = 4\n");
    write(1, buffer, strlen(buffer));
    exit(1);
}

void error_y_exit(int n, char* msg) {
    perror(msg);
    exit(n);
}


void trat(int n) {
    if (n == SIGALRM) {
        char buffer_prueba[255];
        sprintf(buffer_prueba, "Eres un hijo de puta\n");
        write(1, buffer_prueba, strlen(buffer_prueba));
        para = 1;
    }
}


void main(int argc, char* argv[]) {
    if (argc != 3) Usage();

    sigset_t mask;
    sigfillset(&mask);
    struct sigaction t;
    sigemptyset(&t.sa_mask);
    t.sa_handler = trat;
    t.sa_flags = 0;
    if (sigaction(SIGCHLD, &t, NULL) < 0) error_y_exit(1, "SIGACTION");
    if (sigaction(SIGALRM, &t, NULL) < 0) error_y_exit(1, "SIGACTION");
    sigdelset(&mask, SIGCHLD);
    sigdelset(&mask, SIGALRM);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error_y_exit(1, "SIGPROCMASK");


    int ntextos = atoi(argv[2]);

    for (int i = 0; i < ntextos; ++i) {
        int p[2];
        pipe(p);
    
        int pid = fork();

        if (pid < 0) error_y_exit(1, "FORK");
        else if (pid == 0) {
            dup2(p[1], 1);
            close(p[1]);
            close(p[0]);
            
            char buffer[255];
            char buffer2[255];
            sprintf(buffer, "%d", i);
            sprintf(buffer2, "%d", ntextos);
            execlp("./decod", "decod", argv[1], buffer2, buffer, NULL);
            error_y_exit(1, "EXECLP");
        }
        close(p[1]);
        alarm(2);

        char buffer3[255];

        while (para == 0) {

        }
        kill(pid, SIGUSR1);
        
        sprintf(buffer3, "HOLAAA\n");
        write(1, buffer3, strlen(buffer3));

        sigsuspend(&mask);

        sprintf(buffer3, "HOLAAA2\n");
        write(1, buffer3, strlen(buffer3));

        char c;
        while (read(p[0], &c, sizeof(char)) > 0) {
            write(1, &c, sizeof(char));
        }
        close(p[0]);

        char buffer[255];
        sprintf(buffer, "\n");
        write(1, buffer, strlen(buffer));
    }
    sbrk(-sizeof(int));
}