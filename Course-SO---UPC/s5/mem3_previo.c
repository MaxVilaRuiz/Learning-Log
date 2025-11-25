#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int *p;

void Usage(char *arg) {
    char buf[128];

    sprintf(buf, "%s: parametros invalidos\n%s: usage: %s\n", arg, arg, arg);
    write(2, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    char buff[256];

    if (argc != 1) Usage(argv[0]);

    sprintf(buff, "Dirección de p: %p\n", &p);
    write(1, buff, strlen (buff));
    sprintf(buff, "Valor de p: %p\n", p);
    write(1, buff, strlen (buff));

    *p = 5;

    exit(EXIT_SUCCESS);
}
