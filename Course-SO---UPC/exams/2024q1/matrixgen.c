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
    if (argc < 3 || 4 < argc) Usage();

    int r = atoi(argv[1]);
    int c = atoi(argv[2]);
    if (r < 0 || c < 0) Usage();

    int* m = malloc(r * c * sizeof(int));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i*c + j] = i*c + j;
        }
    }

    int fd = 1;
    if (argc == 4) fd = open(argv[3], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, m, r * c * sizeof(int));

    free(m);

    return 0;
}