#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <fcntl.h>

void Usage() {
    char buff[32];
    sprintf(buff, "Usage: ...\n");
    write(1, buff, strlen(buff));
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) Usage();

    int p[2];
    pipe(p);

    int ret = fork();
    if (ret == 0) {
        close(p[0]);
        dup2(p[1], 1);
        close(p[1]);

        execlp("cat", "cat", argv[1], NULL);
    }

    int ret2 = fork();
    if (ret2 == 0) {
        close(p[1]);
        dup2(p[0], 0);
        close(p[0]);

        char cmd[32];
        sprintf(cmd, "-w%i", atoi(argv[2]));
        execlp("od", "od", "-t", "d4", cmd, NULL);
    }

    close(p[0]);
    close(p[1]);

    while (waitpid(-1, NULL, 0) > 0);

    return 0;
}