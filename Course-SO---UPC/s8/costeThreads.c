#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
    pthread_t tid = pthread_self();
    printf("Thread creado. TID = %lu\n", (unsigned long)tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <num_threads>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "El número debe ser positivo\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        pthread_t tid;

        if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }

        pthread_join(tid, NULL);
    }

    return 0;
}