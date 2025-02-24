#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Pre: v no está vacío
// Post: max_val = máximo de v AND min_val = mínimo de v
void buscar_max_min(const vector<double>& v, double& max_val, double& min_val) {
  // Inicializamos con los valores extremos posibles
  max_val = numeric_limits<double>::lowest();  // Mínimo representable
  min_val = numeric_limits<double>::max();     // Máximo representable
  
  // Invariante: (se cumple al inicio de cada iteración)
  //   max_val es el máximo de v[0..i-1] AND
  //   min_val es el mínimo de v[0..i-1]
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] > max_val) max_val = v[i]; // Actualiza el máximo
    if (v[i] < min_val) min_val = v[i]; // Actualiza el mínimo
  }
}

int main() {
  vector<double> v = {3.5, -2.1, 8.7, 4.2, 0.0, -6.3};
  double max_val, min_val;
  
  // Pre: v no está vacío
  buscar_max_min(v, max_val, min_val);
  // Post: max_val = máximo de v AND min_val = mínimo de v
  
  cout << "Máximo: " << max_val << endl;
  cout << "Mínimo: " << min_val << endl;
  
  return 0;
}
