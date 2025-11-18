#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REGION_SIZE 4096

void Usage(char *arg) {
    char buf[128];

    sprintf(buf, "%s: parametros invalidos\n%s: usage: %s\n", arg, arg, arg);
    write(2, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

void error_and_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int *p;
int i = 0;

int main (int argc, char *argv[]) {
    char buff[128];

    if (argc != 1) Usage(argv[0]);

    if ((p = sbrk(REGION_SIZE)) < 0) error_and_exit("sbrk");
    sprintf(buff, "Dirección puntero p: %p, Valor puntero p: %p\n", &p, p);
    write(1, buff, strlen(buff));

    while (1) {
        *p = i;
        sprintf(buff, "Valor puntero p: %p, Contenido apuntado por p: %d\n", p, *p);
        write(1, buff, strlen(buff));
        p++;
        i++;
    }
}
