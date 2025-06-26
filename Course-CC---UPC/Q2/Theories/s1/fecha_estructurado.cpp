#include <iostream>

using namespace std;

struct Fecha {
	int dia, mes, any;
};

// Pre: True
// Post: Lee una fecha de la entrada estandar y la devuelve
Fecha fecha_lee();

// Pre: True
// Post: Devuelve la fecha de hoy
Fecha fecha_hoy();

// Pre: f es una fecha válida
// Pre: Escribe por la salida estandar la fecha f
void fecha_escribe(const Fecha& f);

// Pre: f es una fecha válida y d es positivo
// Post: Suma a la fecha f el número de dias d
void fecha_suma_dias(Fecha& f, int d);

// Pre: f1 y f2 son dos fechas válidas
// Post: Devuelve True si f1 es menos que f2, si no False
bool fecha_menor(const Fecha& f1, const Fecha& f2);

// Pre: f1 y f2 son dos fechas válidas
// Post: Devuelve True si las fechas f1 y f2 son iguales, si no False
bool fecha_igual(const Fecha& f1, const Fecha& f2);

// Pre: f1 y f2 son dos fechas válidas
// Post: Devuelve el número de dias entre las fechas f1 y f2
int fecha_dias_entre(const Fecha& f1, const Fecha& f2);

int main() {
	// Declaramos fechas
	Fecha hoy = fecha_hoy();
	Fecha f = { 11, 5, 2012 }; // Cuidado: formato interno expuesto!

	if (fecha_menor(f, hoy)) { // Comparar fechas (f < hoy)
		cout << "En el pasado" << endl;
	} else {
		cout << "En el presente/futuro" << endl;
	}

	fecha_suma_dias(f, 10);
	cout << "Dentro de 10 días será: ";
	fecha_escribe(f);
}
