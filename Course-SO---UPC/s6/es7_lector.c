#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char* argv[]) 
{
  int numero;
  char buff[80];

  int n = read(0, &numero, sizeof(int));
  if (n < 0) {
    perror("read");
    exit(-1);
  }
  if (n != sizeof(int)) {
    sprintf(buff, "Error: fichero demasiado pequeño.\n");
    write(1, buff, strlen(buff));
    exit(-1);
  }

  sprintf(buff, "El número de la entrada es: %i.\n", numero);
  write(1, buff, strlen(buff));

  return 0;
}
