#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <num_procesos>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "El número debe ser positivo\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) { // Hijo
            printf("Proceso hijo creado. PID = %d\n", getpid());
            exit(0);
        } else { // Padre
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}