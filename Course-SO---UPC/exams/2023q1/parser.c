#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void Usage() {
    char buff[128];
    sprintf(buff, "La funció s'usa així: ...\n");
    write(1, buff, strlen(buff));
}

int main(int argc, char* argv[]) {
    int fd;
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(1);
        }
    }
    else if (argc == 1) fd = 0;
    else Usage();

    int r, offset = 0, count = 0;
    char c;
    int* v = sbrk(0);
    if (v == (void*)-1) {
        perror("sbrk");
        exit(1);
    }

    while ((r = read(fd, &c, 1)) > 0) {
        if (c == '\n') {
            if ((sbrk(sizeof(int)) == (void*)-1)) {
                perror("sbrk");
                exit(1);
            }
            v[count++] = offset;
        }
        offset++;
    }

    if (r < 0) {
        perror("Error en el read");
        exit(1);
    }

    if (fd != 0) close(fd);

    char buffer[128];
    sprintf(buffer, "%i %lu\n", count, (unsigned long)(sizeof(int) * count));
    write(2, buffer, strlen(buffer));

    if (0 < count) write(4, v, count * sizeof(int));    

    sbrk(-1 * (count * sizeof(int)));

    return 0;
}