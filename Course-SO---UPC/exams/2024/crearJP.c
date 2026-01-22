#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void Usage() {
    char buff[100];
    sprintf(buff, "La función debe recibir un solo parámetro <PID>\n La función retorna la jerarquía de procesos del proceso cuyo PID se recibe en el parámetro.\n");
    write(1, buff, strlen(buff));
    exit(0);
}

int main(int argc, char *argv[]) {
    if (3 < argc || atoi(argv[1]) < 1 || 10 < atoi(argv[1]) || 5 < atoi(argv[2]) || atoi(argv[2]) < 1) Usage();

    char buff[80];
    int pid_root = getpid();
    sprintf(buff, "Soy el proceso %i, raiz de la jerarquia", pid_root);

    int ret[atoi(argv[1])];
    for (int i = 0; i < atoi(argv[1]); i++) {
        ret[i] = fork();
        for (int j = 0; j < atoi(argv[2]); j++) {
            ret[i] = fork();
        }
    }

    if (getpid() == pid_root) {
        sigset_t mask;
        sigfillset(&mask);
        sigdelset(&mask, SIGALRM);
        alarm(60);
        sigsuspend(&mask);
    }
}