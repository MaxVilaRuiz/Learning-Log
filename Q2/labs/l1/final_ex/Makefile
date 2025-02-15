random_fechas: fecha.o rng.o main.o
	g++ -o random_fechas fecha.o rng.o main.o

fecha.o: fecha.cc fecha.hh
	g++ -c fecha.cc

rng.o: rng.cc rng.hh
	g++ -c rng.cc

main.o: main.cc fecha.hh rng.hh
	g++ -c main.cc


clean:
	rm -f demo_fechas main.o fecha.o

.PHONY: clean