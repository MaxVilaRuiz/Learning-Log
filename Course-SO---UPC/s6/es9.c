#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    int fd_in, fd_out;
    ssize_t nread, nwritten;
    char buf[BUF_SIZE];

    if (argc != 3) {
        const char msg[] = "Usage: prog <input_file> <output_file>\n";
        write(2, msg, sizeof(msg) - 1);
        return 1;
    }

    fd_in = open(argv[1], O_RDONLY);
    if (fd_in < 0)
        return 1;

    fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0)
        return 1;

    // Leer y procesar por bloques
    while ((nread = read(fd_in, buf, BUF_SIZE)) > 0) {
        // Convertir a mayúsculas
        for (ssize_t i = 0; i < nread; i++) {
            if (buf[i] >= 'a' && buf[i] <= 'z')
                buf[i] = buf[i] - 32; // convertir a mayúscula
        }

        ssize_t total = 0;
        while (total < nread) {
            nwritten = write(fd_out, buf + total, nread - total);
            if (nwritten < 0)
                return 1;
            total += nwritten;
        }
    }

    close(fd_in);
    close(fd_out);

    return 0;
}

