#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define ROWS 1024
#define COLS 1024

int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
int num_threads;

void* sum_matrix(void* arg) {
				int thread_id = *(int*)arg;
				char buffer[256];

				// Calcula los elementos que nos toca sumarÂ
				int total_elements = ROWS * COLS;
				int elements_per_thread = total_elements / num_threads;
				int start = thread_id * elements_per_thread;
				int end = (thread_id == num_threads - 1) ? total_elements : start + elements_per_thread;

				sprintf(buffer,"El thread %d suma desde %d hasta %d\n", thread_id, start, end);
				write(1, buffer, strlen(buffer));

				for (int i = start; i < end; ++i) {
								int row = i / COLS;
								int col = i % COLS;
								C[row][col] = A[row][col] + B[row][col];
				}

				return NULL;
}

void Usage(char *prog)
{
				char buffer[256];
				sprintf(buffer, "Uso: %s <numero_de_threads>\n", prog);
				write(2, buffer, strlen(buffer));
}

int main(int argc, char* argv[]) {

				char buffer[256];		
				if (argc != 2) {
								Usage(argv[0]);
								return 1;
				}

				num_threads = atoi(argv[1]);
				if (num_threads <= 0 || num_threads > ROWS * COLS) {
								sprintf(buffer, "El nÃºmero de threads debe estar entre 1 y %d\n", ROWS * COLS);
								write(2, buffer, strlen(buffer));
								return 1;
				}

				// Inicializar matrices A y B con valores de ejemplo
				for (int i = 0; i < ROWS; ++i) {
								for (int j = 0; j < COLS; ++j) {
												A[i][j] = i + j;
												B[i][j] = i * j;
								}
				}

				pthread_t threads[num_threads];

				for (int i = 0; i < num_threads; ++i) {
								int* tid = malloc(sizeof(int));
								*tid = i;
								// Cada thread recibe como paramtero su ID
								pthread_create(&threads[i], NULL, sum_matrix, tid);
				}

				// Esperamos que acaben
				for (int i = 0; i < num_threads; ++i) {
								pthread_join(threads[i], NULL);
				}

				// Aqui podriamos imprimir la matriz

				// Acumular valores matrix

				return 0;
}

