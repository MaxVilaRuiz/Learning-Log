#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>

#include "socketMng.h"

#define MAXSTRING	1024

static double elapsed_seconds(const struct timespec *t0, const struct timespec *t1) {
	time_t sec = t1->tv_sec - t0->tv_sec;
	long nsec = t1->tv_nsec - t0->tv_nsec;
	if (nsec < 0) {
		sec -= 1;
		nsec += 1000000000L;
	}
	return (double)sec + (double)nsec / 10e9;
}

int main (int argc, char *argv[])
{
				int connectionFD;
				int ret;
				char buffer[MAXSTRING], buffer2[2048];
				char* hello = "Hola servidor!";

				if (argc != 3)
				{
								sprintf (buffer, "Usage: %s socketPath num_peticiones\n", argv[1]);
								write (2, buffer, strlen (buffer));
								exit (1);
				}
				uint peticiones = (uint)atoi(argv[2]);

				// Start timing
				struct timespec t0, t1;
				if (clock_gettime(CLOCK_MONOTONIC, &t0) != 0) {
					perror("clock_gettime");
					exit(1);
				}

				for (uint p = 0; p < peticiones; p++){

				sprintf(buffer,"Creando peticion %d\n", p);
				write(1,buffer, strlen(buffer));

				// Encapsular este codigo en 1 thread
				connectionFD = clientConnection (argv[1]);
				if (connectionFD < 0)
				{
								perror ("Error establishing connection\n");
								exit (1);
				}

				send(connectionFD, hello, strlen(hello), 0);
				read(connectionFD, buffer, sizeof(buffer));

				sprintf(buffer2, "Respuesta del servidor: %s\n", buffer);
				write(1, buffer2, strlen(buffer2));

				closeConnection (connectionFD);
				// Hasta aqui

				}

				// Stop timing
				if (clock_gettime(CLOCK_MONOTONIC, &t1) != 0) {
					perror("clock_gettime");
					exit(1);
				}

				double total = elapsed_seconds(&t0, &t1);
				double avg = total / (double)peticiones;

				sprintf(buffer2, "TOTAL requests=%u total_time=%.6f s avg=%.6f s/request\n", peticiones, total, avg);
				write(1, buffer2, strlen(buffer2));

				return 0;
}



// Peticiones:
// TOTAL requests=1 total_time=10.000516 s avg=10.000516 s/request
// TOTAL requests=2 total_time=20.000597 s avg=10.000298 s/request
// TOTAL requests=3 total_time=30.000906 s avg=10.000302 s/request