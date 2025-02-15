compress:
	tar -czvf nombre-directorio.tar.gz nombre-directorio
.PHONY: compress

clean:
	rm -f demo_fechas main.o fecha.o

.PHONY: clean

demo_fechas: fecha.o main.o
	g++ -o demo_fechas fecha.o main.o

fecha.o: fecha.cc fecha.hh
	g++ -c fecha.cc

main.o: main.cc fecha.hh
	g++ -c main.cc