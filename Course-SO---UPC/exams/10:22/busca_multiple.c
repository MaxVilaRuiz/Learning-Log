#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>


int pid;
char buff[250];
void error_y_exit(char error[]) {
    sprintf(buff, "ERROR: %s \n", error);
    write(1, buff, strlen(buff));
    exit(2);
}



void handler(int s) {
    sprintf(buff, "SIGNAL recibido %d \n", s);
    write(1, buff, strlen(buff));
    if (s == SIGUSR1) {
       
    } else if (s == SIGUSR2) {
        if (pid != 0) kill(pid, SIGUSR2);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) error_y_exit("minArgs");

    char *palabra = argv[1];
    char nArchivos = argc-2;

    sigset_t mask;
    sigemptyset(&mask); 
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigprocmask(SIG_SETMASK, &mask, NULL);

    int pids[nArchivos];
    for (int i = 0; i < nArchivos; ++i) {
        int ret = fork();
        if (ret == 0) {
            int pidHermano;
            if (i == 0) pidHermano = 0;
            else pidHermano = pids[i-1];

            char buff[50];
            sprintf(buff, "%d", pidHermano);
            
                        char buff3[256];
            sprintf(buff3, "Ejecutando con pid hermano %d, y buff %s y palabra %s \n", pidHermano, buff, argv[i+2]);
            write(1, buff3, strlen(buff3));
            execlp("./busqueda_parcial_con_espera", "./busqueda_parcial_con_espera", buff, palabra, argv[i+2], (char*)NULL);
            

            error_y_exit("execpl");
        } else if (ret < 0) error_y_exit("fork");
        else {
            pids[i] = ret;
        }
    }
            char buff2[256];
            sprintf(buff2, "Ultimo hijo %d \n", pids[nArchivos-1]);
            write(1, buff2, strlen(buff2));

    for (int i = 0; i < nArchivos; ++i) {
        waitpid(pids[i], NULL, 0);
        if (i == nArchivos - 1) kill(pids[nArchivos-1], SIGUSR1);
    }
}
