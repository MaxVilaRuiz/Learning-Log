#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REGION_SIZE 4096

const int cons1 = 1;
int resp = 0xDEAD2BAD;
int argn;

void Usage(char *arg) {
    char buf[128];

    sprintf(buf, "%s: parametros invalidos\n%s: usage: %s k n, k and n are positive integers, k is odd, and 2^n > k\n", arg, arg, arg);
    write(2, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

void error_and_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// a Proth number is a natural number X of the form X = k * 2^n + 1, where k and n are positive integers, k is odd, and 2^n > k
void proth(int k, int n, int *X) {
    *X = (k * (cons1 << n)) + cons1;
}

int main(int argc, char *argv[]) {
    int argk;
    char *ptr;
    char buff[80];

    if (argc != 3) Usage(argv[0]);
    //argk = atoi(argv[1]);
    argk = (int)strtol(argv[1], &ptr, 10);
    if ((*ptr != '\0') || (argk < 1) || (argk % 2 == 0)) Usage(argv[0]);
    //argn = atoi(argv[2]);
    argn = (int)strtol(argv[2], &ptr, 10);
    if ((*ptr != '\0') || (argn < 1) || ((cons1 << argn) <= argk)) Usage(argv[0]);

    proth(argk, argn, &resp);
    sprintf(buff, "El número de Proth de %d y %d es %d\n", argk, argn, resp);
    write(1, buff, strlen(buff));

    sprintf(buff, "Soy el proceso %d y reservo %d regiones de memoria\n", getpid(), resp);
    write(1, buff, strlen(buff));

    for (int i = 0; i < resp; i++) {
        if((ptr = malloc(REGION_SIZE)) == NULL) error_and_exit("malloc");
        sprintf(buff, "\tptr: %p, region %d: %p\n", &ptr, i, ptr);
        write(1, buff, strlen(buff));
    }

    sprintf(buff, "Pulsa Return para acabar la ejecución\n");
    write(1, buff, strlen(buff));

    if(read(0, buff, 1) < 0) error_and_exit("read");

    exit(EXIT_SUCCESS);
}
