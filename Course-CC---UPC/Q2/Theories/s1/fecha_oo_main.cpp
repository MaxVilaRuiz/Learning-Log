#include <iostream>
#include "fecha_oo.hpp"

using namespace std;

int main() {
	Fecha hoy = Fecha::hoy();
	Fecha f(10, 2, 2024);

	if (f.menor(hoy)) { // f < hoy
	  cout << "En el pasado" << endl;
	} else {
		cout << "En el presente/futuro" << endl;
	}

	hoy.suma_dias(10);
	cout << "Dentro de 10 días será: ";
	hoy.escribe();

  // Como obtener día o mes?
  // cout << f.dia << endl; // Incorrecto
  // cout << f.get_dia(); << endl; // Correcto (a través de método getter())
}
