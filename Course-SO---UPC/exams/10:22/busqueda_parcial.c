#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void error_y_exit(char error[]) {
    /*
    if (error == "fork") {

    } else (error == "execlp") {
        
    }
    */
    exit(2);
}

int main(int argc, char *argv[]) {
    if (argc < 4) error_y_exit("minArgs");

    int pid = atoi(argv[1]);
    char palabra = argv[2];
    char fichero = argv[3];

    int ret = fork();
    if (ret == 0) {
        execlp("grep", "grep", palabra, fichero);
        error_y_exit("execpl");
    } if (ret < 0) error_y_exit("fork");
    else {
    }

    int i;
    waitpid(-1, &i, 0);
    if (WIFEXITED(pid)) exit(WEXITSTATUS(i));
}
