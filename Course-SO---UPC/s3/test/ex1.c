#include <stdio.h>
#include <string.h>
#include <unistd.h>


int
main(int argc, char *argv[])
{
    int ret = fork();
    if (ret > 0) {
        waitpid(-1, NULL, 0);
        printf("This message is written by %i\n", getpid());
        exit(0);
    }
    else {
        printf("This message is written by %i\n", getpid());
        exit(0);
    }
    return 0;
}