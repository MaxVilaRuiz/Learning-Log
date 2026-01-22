#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_y_exit(int errcode) {
    if (errcode == 1) perror("Error al abrir el archivo");
    if (errcode == 2) perror("Error al añadir memoria al heap");
    return 1;
}

int main(int argc, char *argv[]) {
    int fd;
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {} error_y_exit(1);
    } else {
        fd = STDIN_FILENO;
    }

    int *lineOffsets = (int *)sbrk(0); //Pillamos la direccion inicial del heap para saber desde donde empezamos.
    int *currentEnd = lineOffsets; //Copiamos el puntero inicial, y este es el que se actualiza.
    int lineCount = 0;

    int dist = lseek(fd, 0, SEEK_END); //Contamos caracteres
    lseek(fd, 0, SEEK_SET); //Volvemos a meter el puntero al inicio
    char c;
    for (int i = 0; i < dist; ++i) {
        read(fd, &c, 1);
        if (c == '\n') {
            currentEnd = (int *)sbrk(sizeof(int));
            if (currentEnd == (void *) -1) error_y_exit(2);
            *currentEnd = i;
            lineCount++;
        }
    }
    currentEnd = (int *)sbrk(0); //Esto es porque sbrk devuelve el puntero antes de actualizar, y siempre se queda uno atrasado.
    int memUsage = (currentEnd - lineOffsets) * sizeof(int); //Calculamos diferencia

    //Escribir en canal 1 el mensaje
    char buff[1024];
    sprintf(buff, "El texto tiene %d saltos de línea y se han utilizado %ld bytes del heap\n", lineCount, memUsage);
    write(2, buff, strlen(buff));

    //Escribir en canal 4 las posiciones
    write(4, lineOffsets, memUsage);

    if (fd != STDIN_FILENO) close(fd);
    
    return 0;
}