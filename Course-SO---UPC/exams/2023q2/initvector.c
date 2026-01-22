#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <fcntl.h>

void Usage() {
    char buff[32];
    sprintf(buff, "Usage: ...\n");
    write(2, buff, strlen(buff));
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 2 || 3 < argc) Usage();

    char buff[64];
    int n = atoi(argv[1]);
    if (n % 2 != 0) {
        sprintf(buff, "Error: entrada es impar.\n");
        write(2, buff, strlen(buff));
        exit(1);
    }

    int* vec = malloc((n+1) * sizeof(int));
    if (vec == NULL) {
        perror("malloc");
        exit(1);
    }

    vec[0] = n;
    for (int i = 0; i < n; i++) vec[i+1] = i;

    int fd = 1;
    if (argc == 3) {
        fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0640);
        if (fd < 0) {
            perror("open");
            exit(1);
        }
    }

    write(fd, vec, (n+1) * sizeof(int));

    free(vec);

    return 0;
}