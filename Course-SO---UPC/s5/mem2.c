#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int *ptr = (int *)0xDEAD2BAD;

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

int main(int argc, char *argv[]) {
    char buff[80];

    if (argc != 1) Usage(argv[0]);

    if((ptr = malloc(sizeof(int))) == NULL) error_and_exit("malloc"); 

    *ptr = 0xDAD;
    sprintf(buff, "PADRE %d: valor ptr: %p, contenido inicial %X\n", getpid(), ptr, *ptr);
    write(1, buff, strlen(buff));

    int pid = fork();
    switch(pid) {
        case -1: error_and_exit("fork");
	case 0: sprintf(buff, "HIJO %d: valor ptr: %p, contenido heredado %X\n", getpid(), ptr, *ptr);
                write(1, buff, strlen(buff));
		*ptr = 0xBABE;
	        sprintf(buff, "HIJO %d: valor ptr: %p, contenido modificado %X\n", getpid(), ptr, *ptr);
                write(1, buff, strlen(buff));
                sprintf(buff, "Pulsa Return para finalizar al hijo (y la ejecución)\n");
                write(1, buff, strlen(buff));
                if(read(0, buff, 1) < 0) error_and_exit("read");
                free(ptr);
                exit(EXIT_SUCCESS);
    }

    if(waitpid(pid, NULL, 0) < 0) error_and_exit("wait");
    sprintf(buff, "PADRE %d: valor ptr: %p, contenido final %X\n", getpid(), ptr, *ptr);
    write(1, buff, strlen(buff));
    free(ptr);

    exit(EXIT_SUCCESS);
}
