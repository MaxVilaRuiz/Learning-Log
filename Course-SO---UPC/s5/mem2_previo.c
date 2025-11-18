#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

/* readint - Devuelve un entero leido desde teclado */
int readint(void) {
    char buff[80];
    char *ptr;
    int x;

    if ((x = read(0, &buff, sizeof(buff))) < 0) error_and_exit("read");
    buff[x - 1] = '\0';           //sustituir \n por \0
    x = (int)strtol(buff, &ptr, 10);
    if ((*ptr != '\0') || (x < 1)) return -1;
    return x;
}

void fillvectors(int *vector1, int *vector2, int num_elems) {
    for (int i = 0; i < num_elems; i++) {
        vector1[i] = i % 2 == 0 ? i : 0;
        vector2[i] = i % 2 == 1 ? i : 0;
    }
}

void addvectors(int *vector1, int *vector2, int *s1, int *s2, int num_elems) {
    for (int i = 0; i < num_elems; i++) {
        *s1 += vector1[i];
        *s2 += vector2[i];
    }
}

int vector1[40960];
int vector2[40960];

int main(int argc, char *argv[]) {
    int suma1 = 0, suma2 = 0, n;
    char buff[80];

    if (argc != 1) Usage(argv[0]);

    sprintf(buff, "Soy el proceso %d\n", getpid());
    write(1, buff, strlen(buff));

    sprintf(buff, "Introduce el numero de elementos del vector y pulsa Return: ");
    write(1, buff, strlen(buff));
    if ((n = readint()) < 0) {
        sprintf (buff, "Numero de elementos incorrecto\n");
        write (2, buff, strlen(buff));
        exit(EXIT_FAILURE);
    }

    sprintf(buff, "Dirección del vector1 %p y del vector2 %p\n", vector1, vector2);
    write(1, buff, strlen(buff));

    fillvectors(vector1, vector2, n);
    addvectors(vector1, vector2, &suma1, &suma2, n);

    sprintf(buff, "Suma de los %d elementos del vector1 %d y del vector2 %d\n", n, suma1, suma2);
    write(1, buff, strlen(buff));

    sprintf(buff, "Pulsa Return para acabar la ejecución\n");
    write(1, buff, strlen(buff));

    if(read(0, buff, 1) < 0) error_and_exit("read");

    exit(EXIT_SUCCESS);
}
