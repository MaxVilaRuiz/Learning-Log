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
    exit(1);
}


int main(int argc, char *argv[]) {
int nhijos,i,status,ret,j;
int pidh[10];
char buf[80];


if ((argc < 2) || (argc > MAX_FILES+1)) {
    Usage();
}

nhijos=argc-1;

for (i=0;i<nhijos;i++) {

    pidh[i]=fork();
    switch (pidh[i]) {
    case -1: error_exit("Error creando hijos primer nivel de jerarquia");
    case 0 :sprintf(buf,"Nombre de fichero: %s\n",argv[i+1]);
            write(1,buf,strlen(buf));
            
            for (j=0;j<3;j++){
                ret=fork();
                if (ret <0) error_exit("Error creando hijos segundo nivel de jerarquia");
                sprintf(buf,"%s_sin_repes",argv[i+1]); 
                if (ret==0) {
                    switch(j){
                        case 0: execlp("wc","wc","-l",argv[i+1],(char *) 0);
                                break;
                        case 1: execlp("sort","sort","-u",argv[i+1],"-o",buf,(char *) 0);
                                break;
                        case 2: execlp("wc","wc","-l",buf,(char *) 0);
                    }
                    error_exit("Error mutando a wc");
                }
                waitpid(-1,NULL,0);
             } 

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
