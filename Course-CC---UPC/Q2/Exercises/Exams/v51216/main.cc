#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("ArbreG.hh")
#include "ArbreG.hh"
#endif
#endif

#include "ArbreG-io.hh"

int main() {
	string linea;
	while (getline(cin, linea)) {
		istringstream sin(linea);
		string comando;
		int viejo, nuevo;
		sin >> comando >> viejo >> nuevo;
		assert(comando == "sust");

		ArbreGen<int> arbol = leer_arbol_int();
		int nsust = arbol.sustituir(viejo, nuevo);
		cout << "Se han hecho " << nsust << " sustituciones" << endl;
		escribir_arbol(arbol);
	}
}
