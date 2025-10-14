#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pid;
    char buffer[100];

    pid = fork();
    
    switch (pid)
    {
    case 0:
        sprintf(buffer, "HIJO: Soy el proceso %d y el parámetro es %s\n", getpid(), argv[1]);
        write(1, buffer, strlen(buffer));
        break;
    
    case -1:
        break;

    default:
        sprintf(buffer, "PADRE: Soy el proceso %d\n", getpid());
        write(1, buffer, strlen(buffer));
        break;
    }

    while (1) ;
    
    return 0;
}