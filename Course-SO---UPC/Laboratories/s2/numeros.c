#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8

int
esNumero(char *str)
{
	if (str == NULL || *str == '\0')
		return 0;
	//Puntero nulo o cadena vacía

		int		start = 0;
	if (str[0] == '-') {
		//Signo negativo
			start = 1;
		if (str[1] == '\0')
			return 0;
		//Cadena '-' es incorrecta
	}

	int		count = 0;
	for (int i = start; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return 0;
		//No es dígito
			count++;
		if (count > MAX_SIZE)
			return 0;
		//Más de 8 cifras
	}

	return 1;
	//Cumple condiciones
}


int
main(int argc, char *argv[])
{
	char		buf[80];
	for (int i = 1; i < argc; i++) {
		if (esNumero(argv[i]))
			sprintf(buf, "El argumento %d (%s) es un número.\n", i, argv[i]);
		else
			sprintf(buf, "El argumento %d (%s) no es un número.\n", i, argv[i]);
		write(1, buf, strlen(buf));
	}
}