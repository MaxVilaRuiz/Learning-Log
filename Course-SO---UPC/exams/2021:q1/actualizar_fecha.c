#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void usage() {
}

int main(int argc, char *argv[]) {
    int nArchivos = argc - 1;


    int pids[nArchivos];
    for (int i = 0; i < nArchivos; ++i) {
        int ret = fork();
        if (ret == 0) {
            execlp("touch", "touch", argv[i+1], (char*)NULL);
        } else if (ret < 0) {

        } else {
            pids[i] = ret;
        }
    }

    int pid;
    while (pid = waitpid(-1, NULL, 0) && pid > 0) {
        for (int i = 0; i < nArchivos; ++i) {
            if (pid == pids[i]) {
                char buff[256];
                sprintf(buff, "Fecha %s actualizada por %d \n", argv[i+1], pids[i]);
            }
        }
    }
}