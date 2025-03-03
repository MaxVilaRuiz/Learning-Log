#include <iostream>
#include <map>
#include <string>

using namespace std;

pair<double, string> analizar_notas(const map<string, int>& notas) {
  // Si el mapa está vacío, devolver valores por defecto
  if (notas.empty()) return {0.0, ""}; 

  double suma = 0;
  string mejor_estudiante;
  int mejor_nota = -1;
  for (const auto& [nombre, nota] : notas) {
    suma += nota;
    if (nota > mejor_nota) {
      mejor_nota = nota;
      mejor_estudiante = nombre;
    }
  }
  double media = suma / notas.size();

  return {media, mejor_estudiante};
}

int main() {
  map<string, int> notas = {
    {"Ana", 85},
    {"Luis", 90},
    {"Pedro", 78},
    {"Marta", 95},
    {"Elena", 88}
  };

  pair<double, string> resultado = analizar_notas(notas);
  cout << "Nota media: " << resultado.first << endl;
  cout << "Mejor estudiante: " << resultado.second << endl;

  return 0;
}
