#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include <fcntl.h>
#include <string.h>

void Usage() {
    char buffer[128];
    sprintf(buffer, "La funció s'usa així: ...\n");
    write(1, buffer, strlen(buffer));
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        Usage();
        exit(1);
    }

    int fd_text = open(argv[1], O_RDWR);
    if (fd_text < 0) {
        perror("open text");
        exit(1);
    }

    char outname[32];
    sprintf(outname, "%s.out", argv[1]);
    int fd_out = open(outname, O_RDONLY);
    if (fd_out < 0) {
        perror("open out");
        exit(1);
    }

    int total = lseek(fd_out, 0, SEEK_END) / sizeof(int);
    char buffer[128];
    for (int i = 2; i < argc; i++) {
        int n = atoi(argv[i]);

        if (n < 1 || n > total) {
            sprintf(buffer, "El salto de línea %i no esta en el rango de este fichero\n", n);
            write(1, buffer, strlen(buffer));
            continue;
        }

        int offset;
        lseek(fd_out, (n - 1) * sizeof(int), SEEK_SET);
        read(fd_out, &offset, sizeof(int));

        char c; 
        lseek(fd_text, offset, SEEK_SET);
        read(fd_text, &c, 1);

        if (c == '\n') {
            lseek(fd_text, offset, SEEK_SET);
            write(fd_text, "-", 1);
        }
    }

    close(fd_text);
    close(fd_out);

    return 0;
}