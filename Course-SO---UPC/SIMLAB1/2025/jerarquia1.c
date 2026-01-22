#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

#include "error_exit.h"

#define MAX_FILES 10

void Usage() {
    char buf[80];
    strcpy(buf,"Usage: jerarquia1 file1 [file2 .... file10]\n");
    write(1,buf,strlen(buf));
    exit(255);
}

int main(int argc, char *argv[]) {
int nhijos,i,status;
int pidh[10];
char buf[80];


if ((argc < 2) || (argc > MAX_FILES+1)) {
    Usage();
}

nhijos=argc-1;

for (i=0;i<nhijos;i++) {

    pidh[i]=fork();
    switch (pidh[i]) {
    case -1: error_exit("Error en creando hijos");
    case 0 :sprintf(buf,"Nombre de fichero: %s\n",argv[i+1]);
            write(1,buf,strlen(buf));
            exit(i);
    }

}

i=0;
while (waitpid(pidh[i],&status,0)>0) {
        if (WIFEXITED(status)) {
            sprintf(buf,"Pid del hijo muerto es %d, parametro del exit es %d\n", pidh[i],WEXITSTATUS(status));
            write(1,buf,strlen(buf));
        } 
        i++;
}


}
