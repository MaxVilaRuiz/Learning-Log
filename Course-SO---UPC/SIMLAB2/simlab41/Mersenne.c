#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 4

int main() {
    mknod("ff1", S_IFIFO | 0666, 0);
    mknod("ff2", S_IFIFO | 0666, 0);

    int fd[2];
    int ret = pipe(fd);

    int p1 = fork();
    if (p1 == 0) {
        dup2(fd[1], 1);
        //close(0);
        int ff1 = open("ff1", O_RDONLY);
        dup2(ff1, 0);
        close(ff1);
        close(fd[1]);
        close(fd[0]);
        execlp("./arith", "arith", "2", (char *)NULL);
    }

    int p2 = fork();
    if (p2 == 0) {
        dup2(fd[0], 0);
        //close(1);
        int ff2 = open("ff2", O_WRONLY);
        dup2(ff2, 1);
        close(ff2);
        close(fd[0]);
        close(fd[1]);
        execlp("./arith", "arith", "1", (char *)NULL);
    }

    close(fd[0]);
    close(fd[1]);

    int values[BUFFER_SIZE];
    int ff1 = open("ff1", O_WRONLY);
    char buff2[128];
    int j;
    while(read(0, &j, sizeof(j)) > 0) {

        sprintf(buff2, "NG \n");
        write(2, buff2, strlen(buff2));

        write(ff1, &j, sizeof(j));
    }
    close(ff1);

    int ff2 = open("ff2", O_RDONLY);
    int i;
    char buf[80];
    while(read(ff2, &i, sizeof(i)) > 0) {
        sprintf(buf, "%d ", i);
        write(1, buf, strlen(buf));
    }
    sprintf(buf, "\n");
    write(1, buf, strlen(buf));
    close(ff2);

     while ((waitpid(-1, NULL, 0)) > 0);
}