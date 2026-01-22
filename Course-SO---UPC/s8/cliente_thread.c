#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>

#include "socketMng.h"

#define MAXSTRING 1024

/* Structure passed to each thread */
typedef struct {
    const char *socketPath;
    unsigned int id;
    int quiet;
} thread_arg_t;

/* Thread routine: performs one request */
void *request_thread(void *arg) {
    thread_arg_t *targ = (thread_arg_t *)arg;
    int connectionFD;
    char buffer[MAXSTRING];
    const char *hello = "Hola servidor!";

    /* Connect to server */
    connectionFD = clientConnection((char *)targ->socketPath);
    if (connectionFD < 0) {
        perror("clientConnection");
        pthread_exit(NULL);
    }

    /* Send request */
    send(connectionFD, hello, strlen(hello), 0);

    /* Read response */
    ssize_t r = read(connectionFD, buffer, sizeof(buffer) - 1);
    if (r >= 0) {
        buffer[r] = '\0';
        if (!targ->quiet) {
            printf("Thread %u - server reply: %s\n", targ->id, buffer);
        }
    }

    closeConnection(connectionFD);
    pthread_exit(NULL);
}

/* Compute elapsed seconds */
static double elapsed_seconds(const struct timespec *t0,
                              const struct timespec *t1) {
    time_t sec = t1->tv_sec - t0->tv_sec;
    long nsec = t1->tv_nsec - t0->tv_nsec;
    if (nsec < 0) { sec--; nsec += 1000000000L; }
    return (double)sec + (double)nsec / 1e9;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s socketPath num_peticiones\n", argv[0]);
        exit(1);
    }

    unsigned int peticiones = (unsigned int)atoi(argv[2]);
    if (peticiones == 0) {
        fprintf(stderr, "num_peticiones must be >= 1\n");
        exit(1);
    }

    pthread_t *threads = malloc(sizeof(pthread_t) * peticiones);
    thread_arg_t *args = malloc(sizeof(thread_arg_t) * peticiones);

    if (!threads || !args) {
        perror("malloc");
        exit(1);
    }

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    /* Create one thread per request */
    for (unsigned int i = 0; i < peticiones; i++) {
        args[i].socketPath = argv[1];
        args[i].id = i;

        if (pthread_create(&threads[i], NULL, request_thread, &args[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    /* Wait for all threads */
    for (unsigned int i = 0; i < peticiones; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);

    double total = elapsed_seconds(&t0, &t1);
    double avg = total / peticiones;

    printf("THREADED: requests=%u total_time=%.6f s avg=%.6f s/request\n",
           peticiones, total, avg);

    free(threads);
    free(args);

    return 0;
}




// Peticiones:
// THREADED: requests=1 total_time=10.005315 s avg=10.005315 s/request
// THREADED: requests=2 total_time=20.007982 s avg=10.003991 s/request
// THREADED: requests=3 total_time=30.009803 s avg=10.003268 s/request