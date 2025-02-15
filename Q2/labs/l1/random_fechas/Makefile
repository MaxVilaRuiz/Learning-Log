demo_rng: rng.o main.o
	g++ -o demo_rng rng.o main.o

rng.o: rng.cc rng.hh
	g++ -c rng.cc

main.o: main.cc rng.hh
	g++ -c main.cc