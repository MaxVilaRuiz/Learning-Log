CXX := g++
CXXFLAGS := -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

test_files := $(wildcard *.inp)

# Compila amb les opcions de PRO2
main.exe: queue.hh main.cc
	$(CXX) $(CXXFLAGS) -o main.exe main.cc

# `make test`: testeja el programa amb els fitxers *.inp
test: main.exe
	$(foreach file, $(test_files), \
		echo $(file); \
		./main.exe < $(file); \
		echo;)

# Neteja
clean:
	rm -f main.exe

.PHONY: test