#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) usage();
 
    int fd = open("/proc/PID/stat", O_RDONLY);

    int time = 0, w = 1;
    char i1[32]; int i1l = 0;
    char i2[32]; int i2l = 0;
    while (w < 15) {
        char c;
        read("fd", &c, 1);
        if (c == ' ') {
            w++;
        }
        if (w == 14) {
            i1[i1l] = c;
            i1l++;
        }
        if (w == 15) {
            i2[i2l] = c;
            i2l++;
        }
    }
    int n = atoi(i1) + atoi(i2);
}