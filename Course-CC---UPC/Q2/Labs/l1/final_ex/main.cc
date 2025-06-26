#include <ctime>	// time, localtime, tm, ...
#include <fstream>	// Leer y escribir ficheros
#include <iomanip>	// setfill, setw
#include <iostream>
#include <vector>
#include <random>
#include "fecha.hh"
#include "rng.hh"

using namespace std;

int main() {
	const int NUM_FECHAS = 10000; // Cantidad de fechas que se generan
	const int MAX_DISTANCIA = 30; // Distancia máxima en días entre 
                           	  // dos fechas consecutivas

	RNG rng;
	rng_init(rng);

	Fecha fecha = fecha_actual();
	fecha_escribir(fecha);
	
	for (int i = 0; i < NUM_FECHAS; i++) {
		int r_dia = rng_generate(rng, 1, MAX_DISTANCIA);
		fecha = fecha_sumar_dias(fecha, r_dia);

		fecha_escribir(fecha);
		cout << endl;
	}
}