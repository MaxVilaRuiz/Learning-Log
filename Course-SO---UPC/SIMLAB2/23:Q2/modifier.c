#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void usage() {
}
void error_y_exit(int errCode) {
}

int main(int argc, char *argv[]) {
    if (argc < 3) usage();

    char *fileno = argv[2];
    int fd = open(argv[1], O_WRONLY);
}