#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "socketMng.h"

#define MAXSTRING	1024


int server_fd;

int main (int argc, char *argv[])
{
				int socketFD;
				int connectionFD;
				char buffer[MAXSTRING];
				char buffer_msg[MAXSTRING];
				int ret;

				if (argc != 2)
				{
								sprintf(buffer, "Usage: %s socketPath\n", argv[1]);
								write (2, buffer, strlen (buffer));
								exit (1);
				}

				socketFD = createSocket (argv[1]);
				if (socketFD < 0)
				{
								perror ("Error creating socket\n");
								exit (1);
				}
			
				while(1)
				{
				// Esta funcion acepta una nueva conexion de un cliente
				// devuelve un nuevo canal, connectionFD, especifico con el proceso
				// que hace la peticion del servicio
	
				sprintf(buffer,"Esperando conexiones de clientes\n");
				write(1,buffer,strlen(buffer));

				connectionFD = serverConnection (socketFD);
				if (connectionFD < 0)
				{
								perror ("Error establishing connection \n");
								exit (1);
				}
				sprintf(buffer,"Nueva conexcion FD=%d\n", connectionFD);
				write(1,buffer, strlen(buffer));

				// Esta parte hay que encapsularla para hacerla en 1 thread: recibe como parametro el 
				// connectionFD, que es un canal para una peticion concreta

				// En este punto somos los encargados de atender un cliente concreto
				read(connectionFD, buffer_msg, sizeof(buffer_msg));

				sprintf(buffer, "Mensaje recibido: %s\n", buffer_msg);
				write(1,buffer, strlen(buffer));

				// El sleep simplemente simula un coste del servicio
				sleep(10);

				sprintf(buffer, "Enviando respuesta\n");
				write(1,buffer, strlen(buffer));

				char* response = "Hola desde el servidor\n";
				send(connectionFD, response, strlen(response), 0);
				close(connectionFD);
				// Hasta aqui (final del codigo que ha de ejecutar el thread)
				}

				// eliminamos el socket 
				deleteSocket (socketFD, argv[1]);
				return 0;
}



