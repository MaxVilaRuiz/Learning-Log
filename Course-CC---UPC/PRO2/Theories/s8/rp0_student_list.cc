/*
 * Repaso 5. Dada una lista de pares (nombre, nota) que representan 
 * calificaciones de distintos alumnos (puede haber varios registros  
 * por alumno), calcula la media de notas por alumno.
 *   Santi 7
 *   Laura 10
 *   Santi 9
 *   ...
 */

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  map<string,pair<int,int>> datos; // nombre -> <suma_notas,num_notas>
  
  // Leer pares del fichero
  string nombre;
  int nota;
  while (cin >> nombre >> nota) {
    datos[nombre].first += nota;
    ++(datos[nombre].second);
  }
  
  // Imprimir por pantalla nombre y media
  for (const auto& [nombre, info] : datos) {
    double media = double(info.first) / info.second;
    cout << nombre << " => " << media << endl; 
  }

  return 0;
}
