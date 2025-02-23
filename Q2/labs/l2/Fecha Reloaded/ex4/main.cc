// g++ -o fechas main.cc fecha.cc

#include <iostream>
#include <vector>
#include "fecha.hh"
using namespace std;


int dias_dif(const Fecha& f1, const Fecha& f2) {
	Fecha fecha1 = f1;
	Fecha fecha2 = f2;
	int dies = 0;

	while (fecha1.menor(fecha2)) {
		fecha1 = fecha1.suma_dias(1);
		dies++;
	}

	while (fecha1.mayor(fecha2)) {
		fecha2 = fecha2.suma_dias(1);
		dies++;
	}

	return dies;
}


int main() {
	Fecha f1;
	Fecha f2;
	cin >> f1;
	cin >> f2;
	cout << dias_dif(f1, f2) << endl;
}