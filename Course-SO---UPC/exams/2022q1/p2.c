#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "errno.h"

void Usage() {
    char buff[64];
    sprintf(buff, "Usage: ...\n");
    write(1, buff, strlen(buff));
    exit(1);
}

int count = 0;
void alrm_handler(int signal) {
    count = 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || (argc % 2) == 0) Usage();

    if (mkfifo("MYPIPE", 0600) < 0 && errno != EEXIST) {
        perror("mkfifo");
        exit(1);
    }

    int fd = open("MYPIPE", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = alrm_handler;
    if (sigaction(SIGALRM, &sa, 0) < 0) {
        perror("sigaction");
        exit(1);
    } 

    char buff[64];

    for (int i = 1; i < argc; i+=2) {
        int ret = fork();

        if (ret == 0) {
            if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
                perror("sigprocmask");
                exit(1);
            }
            
            int fd2 = open("MYPIPE", O_WRONLY); 
            if (dup2(fd2, 10) < 0) {
                perror("dup2");
                exit(1);
            }
            close(fd2);

            execlp("./p1", "p1", argv[i], argv[i+1], NULL);

            perror("execlp");
            exit(1);
        }
    
        count = 0;
        alarm(2);
        while (count == 0) {}

        kill(ret, SIGUSR1);

        int* arr;
        int count2 = 0;
        if (argv[i+1][0] == 'c') {
            arr = malloc(atoi(argv[i]) * sizeof(char));
            
            char c1;
            while (read(fd, &c1, sizeof(char)) > 0) {
                arr[count2] = c1;
                count2++;
            }

            sprintf(buff, "salida-%i.dat", ret);
            int fd3 = open(buff, 0640);
            write(fd3, arr, atoi(argv[i]) * sizeof(char));
        }
        else {
            arr = malloc(atoi(argv[i]) * sizeof(int));

            int i1;
            while (read(fd, &i1, sizeof(int)) > 0) {
                arr[count2] = i1;
                count2++;
            }

            sprintf(buff, "salida-%i.dat", ret);
            int fd3 = open(buff, O_CREAT | O_TRUNC | O_WRONLY, 0660);
            write(fd3, arr, atoi(argv[i]) * sizeof(int));
            close(fd3);
        }

        free(arr);

        waitpid(ret, NULL, 0);
    }

    close(fd);
    unlink("MYPIPE");

    sprintf(buff, "Final del proceso principal\n");
    write(1, buff, strlen(buff));

    return 0;
}