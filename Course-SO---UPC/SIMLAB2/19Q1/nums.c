#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fdPipe[2];
    int p = pipe(fdPipe);

    int ret = fork();
    if (ret == 0) {
        close(fdPipe[1]);
        int numb;
        char buff[128];
        while(read(fdPipe[0], &numb, sizeof(int)) > 0) {
            numb = numb + 1;
            sprintf(buff, "%d\n", numb);
            write(1, buff, strlen(buff));
        }
        close(fdPipe[0]);
        exit(0);
    } else {
        close(fdPipe[0]);
        int fd = open("crear_numeros_bin", O_RDONLY);
        int dist = lseek(fd, -sizeof(int), SEEK_END);
        for (int i = dist; i >= 0; i=i-sizeof(int)) {
            lseek(fd, i, SEEK_SET);
            int x;
            read(fd, &x, sizeof(int));
            write(fdPipe[1], &x, sizeof(x));
        }
        close(fdPipe[1]);
    }
}