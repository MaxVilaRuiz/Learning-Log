#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXBUFFER 5
#define MAXVALORS 10
#define MAXPROD 10
#define MAXCONS 10

int buffer[MAXBUFFER];
int iteradorProd = 0; //Comptador per controlar nombre iteracions productor
int iteradorCons = 0; //Comptador per controlar nombre iteracions consumidor
int comptador = 0; //Comptador ocupacio buffer
int indexProd = 0; //Index de escriptura
int indexCons = 0; //Index de lectura

pthread_mutex_t lockBuf;
pthread_mutex_t prod;
pthread_mutex_t cons;

void *funcProd(void *arg){
	char buf[256],c;
	int max = *(int *)arg;
	int len;
	int myindexProd;
	
	len = sprintf(buf, "Soc Thread Productor: %d (%lu) - Start...\n", (int) gettid(), (unsigned long)pthread_self());
	write(1, buf, len);	

	while (1){
		pthread_mutex_lock(&prod);
		if (iteradorProd >= max){
			pthread_mutex_unlock(&prod);
			len = sprintf(buf, "Final Execucio Productor: %d (%lu)\n", (int) gettid(), (unsigned long)pthread_self());
			write(1, buf, len);
			return NULL;
		}
		pthread_mutex_lock(&lockBuf);
		if (comptador < MAXBUFFER){
			buffer[indexProd] = iteradorProd;
			comptador++;
			pthread_mutex_unlock(&lockBuf);
			indexProd = (indexProd + 1) % MAXBUFFER;
			iteradorProd++;
			pthread_mutex_unlock(&prod);
			len = sprintf(buf, "Productor: %d - index %d - valor %d\n", (int) gettid(), indexProd, iteradorProd); //per depurar
			write(1, buf, len);	 //per depurar
		}
		else  {
			pthread_mutex_unlock(&lockBuf);
			pthread_mutex_unlock(&prod);
		}
		sleep(1);
	}	
}

void *funcCons(void *arg){
	char buf[256],c;
	int max = *(int *)arg;
	int valor;
	int len;
	
	len = sprintf(buf, "Soc Thread Consumidor: %d (%lu) - Start...\n", (int) gettid(), (unsigned long)pthread_self());
	write(1, buf, len);	

	while (1){
		pthread_mutex_lock(&cons);
		if (iteradorCons >= max){
			pthread_mutex_unlock(&cons);
			len = sprintf(buf, "Final Execucio Consumidor: %d (%lu)\n", (int) gettid(), (unsigned long)pthread_self());
			write(1, buf, len);
			return NULL;
		}
		pthread_mutex_lock(&lockBuf);
		if (comptador > 0){
			valor = buffer[indexCons];
			comptador--;
			pthread_mutex_unlock(&lockBuf);
			len = sprintf(buf, "Consumidor: %d - index %d - valor %d\n", (int) gettid(), indexCons, valor); //per depurar
			indexCons = (indexCons + 1) % MAXBUFFER;
			iteradorCons++;
			pthread_mutex_unlock(&cons);

			write(1, buf, len);	 //per depurar
		}
		else {
			pthread_mutex_unlock(&lockBuf);
			pthread_mutex_unlock(&cons);
		}
		sleep(1);
	}	
}


int main(int argc, char **argv){
	char buf[256];
	int i, len, maxProds, maxCons, max=MAXVALORS;
	pthread_t thsProd[MAXPROD], thsCons[MAXCONS];
	
	if (argc!=3) {
		len = sprintf(buf, "Parametres Entrada Incorrecte\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}

	maxProds = atoi(argv[1]);
	if (maxProds > 10){
		len = sprintf(buf, "Introduir un valor inferior (<11) com primer parametre (productors)\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}

	maxCons = atoi(argv[2]);
	if (maxCons > 10){
		len = sprintf(buf, "Introduir un valor inferior (<11) com segon parametre (consumidors)\n");
		write(1, buf, len);
		return EXIT_FAILURE;
	}
		
	len = sprintf(buf, "Parent process: %d\n", getpid());
	write(1, buf, len);
	
	pthread_mutex_init(&lockBuf, NULL);
	pthread_mutex_init(&cons, NULL);
	pthread_mutex_init(&prod, NULL);

	for (i=0; i < maxProds; i++){
		if (pthread_create(&thsProd[i], NULL, funcProd, (void *)&max) < 0){
			perror("Error en thread create Productor");
			return EXIT_FAILURE;
		}
	}

	for (i=0; i < maxCons; i++){
		if (pthread_create(&thsCons[i], NULL, funcCons, (void *)&max) < 0){
			perror("Error en thread create Consumidor");
			return EXIT_FAILURE;
		}
	}

	for (i=0; i < maxProds; i++)
		pthread_join(thsProd[i], NULL);

	for (i=0; i < maxCons; i++)
		pthread_join(thsCons[i], NULL);
	
	len = sprintf(buf, "Final Execucio.\n");
	write(1, buf, len);

	return EXIT_SUCCESS;
}
