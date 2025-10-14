#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void Usage() {
    char buffer[80];

    sprintf(buffer, "./jerarquia1 file1 file2 file3 ...\n");
    write(1, buffer, strlen(buffer));

    sprintf(buffer, "To create a process child for each file entered in the input and know the pid, the corresponding file and the exit status of each child. Moreover, every child will create a group of 3 process brothers that will execute a command sequence.\n");
    write(1, buffer, strlen(buffer));
}

int main(int argc, char *argv[]) {
    char buffer[2000];
    int pid_childs[argc-1], ret;

    if ((argc < 2 || 11 < argc)) Usage();

    for (int i = 0; i < argc-1; i++) {
        pid_childs[i] = fork();
        switch (pid_childs[i]) {
            case -1:
                // sprintf(buffer, "ERROR: %s", errno);
                write(1, buffer, strlen(buffer));
                break;

            case 0:
                sprintf(buffer, "El nombre del fichero que me ha tocado es: %s\n", argv[i+1]);
                write(1, buffer, strlen(buffer));

                for (int j = 0; j < 3; j++) {
                    ret = fork();
                    if (ret < 0) {
                        // sprintf(buffer, "ERROR: %s", errno);
                    }
                    else if (ret == 0) {
                        switch(j) {
                            case 0:
                                execlp("wc", "wc", "-l", argv[i+1], (char *) 0);
                                break;

                            case 1:
                                execlp("sort", "sort", "-u", argv[i+1], "-o", buffer, (char *) 0);
                                break;

                            case 2:
                                execlp("wc", "wc", "-l", buffer, (char *) 0);
                                break;
                        }
                    }
                }

                exit(i);
                break;
        }
    }

    int status, pid_child;
    for (int i = 0; i < argc-1; i++) {
        pid_child = wait(&status);
        if (WIFEXITED(status)) {
            sprintf(buffer, "El fill amb PID %i ha deixat el següent codi d'èxit: %i\n", pid_child, WEXITSTATUS(status));
            write(1, buffer, strlen(buffer));
        }
    }

    return 0;
}