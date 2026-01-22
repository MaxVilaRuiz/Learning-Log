BINARIES=suma_paralela cliente server cliente_thread

all:$(BINARIES)

suma_paralela:suma_paralela.c
	gcc -o suma_paralela suma_paralela.c

cliente:cliente.c socketMng.h socketMng.c
	gcc -o cliente cliente.c socketMng.c

cliente_thread: cliente_thread.c socketMng.h socketMng.c
	gcc -o cliente_thread cliente_thread.c socketMng.c

server:server.c socketMng.c socketMng.h
	gcc -o server server.c socketMng.c

clean:
	rm -f $(BINARIES)
	

