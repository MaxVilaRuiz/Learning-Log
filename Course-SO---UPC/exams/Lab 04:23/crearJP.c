#include <stdio.h>
#include <unistd.h>
#include <string.h>


void usage() {

}
void errorExit() {

}

int main(int argc, char *argv[]) {
    if (argc <= 2) usage();
    
    char buff[256];
    int archivos = argc - 1;
    int pids[archivos];

    for (int i = 0; i < archivos; ++i) {
        int ret = fork();
        if (ret == 0) {
            sprintf(buff, "el pid del proceso hijo es %d y trata el archivo %s \n", getpid(), argv[1+i]);
            write(1, buff, strlen(buff));
            exit(0);
        } else if (ret < 0) {}
        else pids[i] = ret;
    }

    for (int i = 0; i < archivos; ++i) {
        waitpid(pids[i], null, null);
    }
}