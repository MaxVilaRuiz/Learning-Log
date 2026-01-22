#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>


void error_exit(char * msg) {
    perror(msg);
    exit(255);
}

