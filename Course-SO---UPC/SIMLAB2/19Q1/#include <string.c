#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

Usage() {
    char buf[50];
    sprintf(buf, "Usage: invalid parametres\n");
    write(1, buf, strlen(buf));
    exit(1);
}

void error_y_exit(char* msg, int ex) {
    perror(msg);
    exit(ex);
}

int main(int argc, char* argv[]) {
    if (argc != 2) Usage();
    char buf[80], c;
    int pid = atoi(argv[1]);
    int fd, i = 0, counter = 0;
    sprintf(buf, "/proc/%d/stat", pid);
    fd = open(buf, O_RDONLY);
    if (fd < 0) error_y_exit("open", 255);
    off_t offset;
    while(read(fd, &c, sizeof(c)) > 0 && i < 15) {
        if (c == ' ') ++i;
        if (i == 14) {
            read(fd, &c, sizeof(c));
            int num = atoi(c);
            counter += num;
            while (c != ' ') {
                read(fd, &c, sizeof(c));
                if (c != ' ') {
                    num = atoi(c);
                    counter += num;
                }
            }
            ++i;
        }
        read(fd, &c, sizeof(c));
            int num = atoi(c);
            counter += num;
            while (c != ' ') {
                read(fd, &c, sizeof(c));
                if (c != ' ') {
                    num = atoi(c);
                    counter += num;
                }
            }
    }
}