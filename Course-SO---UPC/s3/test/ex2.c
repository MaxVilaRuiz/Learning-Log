#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Alla voy!\n");
    for (int i = 0; i < 3; i++) {
        fork();
    }
    printf("Buenos días!\n");
    return 0;
}