#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //if (argc < 2) usage();
        char buff[128];

    int i;
    while(read(0, &i, sizeof(int))) {

        sprintf(buff, "HOLA");
        write(2, buff, strlen(buff));

        if (atoi(argv[1]) == 1) i = i-1;
        else i = 1<<i;
        write(1, &i, sizeof(int));


        sprintf(buff, "%d", i);
        write(2, buff, strlen(buff));
    }
}
