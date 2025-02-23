
window_stop_motion: main.o window.o
	g++ -std=c++17 -g3 -o window_stop_motion main.o window.o -lX11 

main.o: main.cc window.hh
	g++ -std=c++17 -g3 -c main.cc

window.o: window.cc window.hh
	g++ -std=c++17 -g3 -c window.cc

clean:
	rm -f window_stop_motion *.o

.PHONY: clean all