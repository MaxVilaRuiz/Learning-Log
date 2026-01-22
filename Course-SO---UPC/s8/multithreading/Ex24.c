#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX 10
#define MAXASCII 128

int asciiCodes[MAXASCII];

pthread_mutex_t lock;

void *func(void *arg){
	char buf[256],c;
	int fd = *(int *)arg;
	int len;
	
	len = sprintf(buf, "Soc Thread: %d (%lu) - Start...\n", (int) gettid(), (unsigned long)pthread_self());
	write(1, buf, len);
	
	while(read(fd, &c, 1) > 0){
		len = sprintf(buf, "%c - %u\n", c, c); //per depurar
		write(1, buf, len); //per depurar
		pthread_mutex_lock(&lock); // yolandab  bajo el lock para reducir la región crítica
		asciiCodes[c]++;
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

int main(int argc, char **argv){
	char buf[256];
	int i, len, maxThs, fd, sumaTotal;
	pthread_t ths[MAX];
	
	if (argc!=3) {
		len = sprintf(buf, "Parametres Entrada Incorrecte\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}

	maxThs = atoi(argv[2]);
	if (maxThs > 10){
		len = sprintf(buf, "Introduir un valor inferior (<11) com segon parametre\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}
		
	len = sprintf(buf, "Parent process: %d\n", getpid());
	write(1, buf, len);
	
	if ((fd = open(argv[1], O_RDONLY)) < 0){
		perror("Error en open");
		return EXIT_FAILURE;
	}
	
	for(i=0; i<MAXASCII; i++)
		asciiCodes[i] = 0;
	
	
	pthread_mutex_init(&lock, NULL);

	for (i=0; i<maxThs; i++){
		if (pthread_create(&ths[i], NULL, func, (void *)&fd) < 0){
			perror("Error en thread create");
			return EXIT_FAILURE;
		}
	}

	for (i=0; i<maxThs; i++){
		pthread_join(ths[i], NULL);
	}
	
	sumaTotal = 0;
	for (i=0; i<MAXASCII; i++){
		sumaTotal += asciiCodes[i];
	}


	len = sprintf(buf, "histograma (codigo ascii: num ocurrencias):\n"); // yolandab <--- he añadido este código para que el padre imprima el histograma
	write(1, buf, len);
	for (i=0; i<MAXASCII; i++){
		len=sprintf(buf, "%d: %d\n", i, asciiCodes[i]);
		write(1,buf,len);
	}
	

	len = sprintf(buf, "Final Execucio. Total: %d\n", sumaTotal);
	write(1, buf, len);

	return EXIT_SUCCESS;
}
