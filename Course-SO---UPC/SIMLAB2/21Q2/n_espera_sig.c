#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    //if (argc < 2) usage();

    int N = atoi(argv[1]);
    int *pids = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        int ret = fork();
        if (ret == 0) {
            char buff[256];
            sprintf(buff, "Hijo con pid: %d\n", getpid());
            write(1, buff, strlen(buff));
            execlp("./espera_sig", "./esper_sig", (char *)NULL);
        } else {
            pids[i] = ret;
        }
    }

    int fd = open("exit_status.int", O_CREAT | O_TRUNC | O_WRONLY, 0777);
    int pid, stat;
    while((pid = waitpid(-1, &stat, 0)) > 0) {
        for (int i = 0; i < N; ++i) {
            if (pids[i] == pid) {
                lseek(fd, i * 2 * sizeof(int), SEEK_SET);
                if (WIFEXITED(stat)) {
                    int exit_status = WEXITSTATUS(stat);
                    write(fd, &pid, sizeof(int));
                    write(fd, &exit_status, sizeof(int));
                }
            }
        }
    }
    free(pids);
    close(fd);
}