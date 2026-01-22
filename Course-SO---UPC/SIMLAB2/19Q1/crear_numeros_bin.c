#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./crear_numeros_bin filein\n");
	write(1,&buff,strlen(buff));

	exit(0);
}

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

int main(int argc,char *argv[]){
	if(argc != 2) Usage();

	int fd = open(argv[1],O_RDONLY);
	int fd2 = open("numeros.bin",O_WRONLY | O_CREAT | O_TRUNC, 0666);
	char c;
	while(read(fd,&c,sizeof(char)) > 0)
	{
		char *aux = &c;
		int x = atoi(aux);
		write(fd2,&x,sizeof(int));
	}
}