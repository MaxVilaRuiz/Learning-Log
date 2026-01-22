#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/errno.h>

int isValidPID(int PID) {
    const int MAX_PID = 99999;
    assert(PID > 0 && PID < MAX_PID);
    return 1;
}

int main(int argc, char *argv[]) {
    assert(argc == 2);
    int pidProceso = atoi(argv[1]);

    char buff[256];
    sprintf(buff, "el pid es %d \n", pidProceso);
    write(1, buff, strlen(buff));

    if (isValidPID(pidProceso)) {
        int ret = fork();
        if (ret == 0) {
            execlp("pstree", "–p", pidProceso, (char *) 0);
                char buff[256];
                sprintf(buff, "el error es %d \n", errno);
                write(1, buff, strlen(buff));
            assert(errno != ESRCH);
        }
        waitpid(-1, null, "");
    }
}