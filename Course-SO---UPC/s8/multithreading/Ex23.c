#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10

int comptador = 0;

pthread_mutex_t lock;

void *func(void *arg){
	char buf[256];
	int max = *(int *)arg;
	int len, localCount = 0;	
	int *returnValue;
	
	returnValue = malloc(sizeof(int));
	
	len = sprintf(buf, "Soc Thread: %lu - Començo...\n", (unsigned long)pthread_self());
	write(1, buf, len);
	
	pthread_mutex_lock(&lock);
	while(comptador < max){
		comptador++;
		len = sprintf(buf, "Thread: %lu - Comptador:%d\n", (unsigned long)pthread_self(), comptador); //per depurar
		pthread_mutex_unlock(&lock); //yolandab lo muevo antes del write para reducir la región crítica
		write(1, buf, len); //per depurar
		localCount++;
		sleep(1);
		pthread_mutex_lock(&lock);
	}
	pthread_mutex_unlock(&lock);

	len = sprintf(buf, "Soc Thread: %lu - He fet %d increments\n", (unsigned long)pthread_self(), localCount);
	write(1, buf, len);
	*returnValue = localCount;
	
	return returnValue;
}

int main(int argc, char **argv){
	char buf[256];
	int i, len, maxVal, maxThs;
	void *ptr;
	pthread_t ths[MAX];
	
	if (argc!=3) {
		len = sprintf(buf, "Parametres Entrada Incorrecte\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}
	
	maxVal = atoi(argv[1]);
	maxThs = atoi(argv[2]);
	if (maxThs > 10){
		len = sprintf(buf, "Introduir un valor inferior (<11) com segon parametre\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}
		
	len = sprintf(buf, "Parent process: %d\n", getpid());
	write(1, buf, len);
	
	pthread_mutex_init(&lock, NULL);

	for (i=0; i<maxThs; i++){
		if (pthread_create(&ths[i], NULL, func, (void *)&maxVal) < 0){
			perror("Error en thread create");
			return EXIT_FAILURE;
		}
	}

	for (i=0; i<maxThs; i++){
		pthread_join(ths[i], &ptr);
		len = sprintf(buf, "El thread %lu ha fet %d increments\n", (unsigned long)ths[i], *(int *)ptr);
		write(1, buf, len);
	}

	len = sprintf(buf, "Final Execucio\n");
	write(1, buf, len);

	return EXIT_SUCCESS;
}
