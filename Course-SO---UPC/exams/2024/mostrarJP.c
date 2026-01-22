#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define PID_MAX 10000

void Usage() {
    char buff[100];
    sprintf(buff, "La función debe recibir un solo parámetro <PID>\n La función retorna la jerarquía de procesos del proceso cuyo PID se recibe en el parámetro.\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_pid() {
    char buff[100];
    sprintf(buff, "El PID debe estar asociado a algún proceso existente.\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_execlp() {
    char buff[100];
    sprintf(buff, "Error al mutar de el código (execlp).\n");
    write(1, buff, strlen(buff));
    exit(0);
}

int main(int argc, char *argv[]) {
    if (2 < argc) Usage();

    int pid = atoi(argv[1]);
    if (!(0 < pid && pid <= PID_MAX && assert())) error_pid();

    int ret = fork();
    if (ret == 0) {
        if (execlp("pstree", "pstree", "-p", argv[1], NULL) < 0) error_execlp();
    }

    waitpid(-1, NULL, NULL);
    exit(0);
}