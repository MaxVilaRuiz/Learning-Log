#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	char		buf[80];
	for (int i = 0; i < argc; i++) {
		if (i == 0)
			sprintf(buf, "El argumento %d es %s (es el nombre del ejecutable)\n", i, argv[i]);
		else
			sprintf(buf, "El argumento %d es %s\n", i, argv[i]);
		write(1, buf, strlen(buf));
	}

	return 0;
}

// Valores de argc y el vector argv en cada uno de los ejemplos:
// 1. argc = 1; argv[0] = ‘./listaParametros’;
// 2. argc = 2; argv[0] = ‘./listaParametros’; argv[1] = ‘a’
// 3. argc = 3; argv[0] = ‘./listaParametros’; argv[1] = ‘a’;  argv[2] = ‘b’
// 4. argc = 4; argv[0] = ‘./listaParametros’; argv[1] = ‘a’;  argv[2] = ‘b’; argv[3] = ‘c’
// 5. argc = 8; argv[0] = ‘./listaParametros’; argv[1] = ‘1’;  argv[2] = ‘2’; argv[3] = ‘3’; argv[4] = ‘4’; argv[5] = ‘5’; argv[6] = ‘6’; argv[7] = ‘7’ 