#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXBUFFER 5  //Valors a canviar segons la prova a fer
#define MAXVALORS 10  //Valors a canviar segons la prova a fer
#define MAXPROD 10
#define MAXCONS 10

int buffer[MAXBUFFER];
int comptador = 0; //Comptador ocupacio buffer
// yolandab en esta versión con solo 1 productor y 1 consumidor estas variables pueden ser locales
int valorProd = 0;
int iteradorCons = 0;
int indexProd = 0;
int indexCons = 0;

pthread_mutex_t lockBuf;

void *funcProd(void *arg){
	char buf[256],c;
	int max = *(int *)arg;
	int len;
	
	len = sprintf(buf, "Soc Thread Productor: %d (%lu) - Start...\n", (int) gettid(), (unsigned long)pthread_self());
	write(1, buf, len);	

	while (1){
		pthread_mutex_lock(&lockBuf);
		if (comptador < MAXBUFFER){
			buffer[indexProd] = valorProd;
			comptador++;
			pthread_mutex_unlock(&lockBuf);  // yolandab libero lock para reducir tamaño region critica

			len = sprintf(buf, "Productor: %d - index %d - valor %d\n", (int) gettid(), indexProd, valorProd);
			write(1, buf, len);	
			indexProd = (indexProd + 1) % MAXBUFFER;
			valorProd++;
			if (valorProd == MAXVALORS){
				return NULL; // yolandab aqui ya no hace falta unlock
			}
		}else pthread_mutex_unlock(&lockBuf); // este es solo necesario para  si el buffer está lleno
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
		pthread_mutex_lock(&lockBuf);
		if (comptador > 0){
			valor = buffer[indexCons];
			comptador--;
			pthread_mutex_unlock(&lockBuf);
			len = sprintf(buf, "Consumidor: %d - index %d - valor %d\n", (int) gettid(), indexCons, valor);
			write(1, buf, len);	
			indexCons = (indexCons + 1) % MAXBUFFER;
			iteradorCons++;
			if (iteradorCons == MAXVALORS){
				return NULL;
			}
		}
		else pthread_mutex_unlock(&lockBuf);
		sleep(1);
	}	
}


int main(int argc, char **argv){
	char buf[256];
	int i, len, max=MAXVALORS;
	pthread_t thsProd, thsCons;
	
	len = sprintf(buf, "Parent process: %d\n", getpid());
	write(1, buf, len);
	
	pthread_mutex_init(&lockBuf, NULL);

	if (pthread_create(&thsProd, NULL, funcProd, (void *)&max) < 0){
		perror("Error en thread create Productor");
		return EXIT_FAILURE;
	}

	if (pthread_create(&thsCons, NULL, funcCons, (void *)&max) < 0){
		perror("Error en thread create Consumidor");
		return EXIT_FAILURE;
	}

	pthread_join(thsProd, NULL);

	pthread_join(thsCons, NULL);
	
	len = sprintf(buf, "Final Execucio.\n");
	write(1, buf, len);

	return EXIT_SUCCESS;
}
