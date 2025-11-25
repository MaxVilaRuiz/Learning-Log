#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int cons1 = 1;
int *resp;
int argn;

void Usage(char *arg) {
    char buf[128];

    sprintf(buf, "%s: parametros invalidos\n%s: usage: %s k n, k and n are positive integers, k is odd, and 2^n > k\n", arg, arg, arg);
    write(2, buf, strlen(buf));
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

    // Reservar memoria
    resp = (int *) malloc(sizeof(int));
    if (resp == NULL) {
        perror("Error al reservar memoria");
        exit(EXIT_FAILURE);
    }

    proth(argk, argn, resp);
    sprintf(buff, "El número de Proth de %d y %d es %d\n", argk, argn, *resp);
    write(1, buff, strlen(buff));

    // Liberar memoria
    free(resp);

    exit(EXIT_SUCCESS);
}
