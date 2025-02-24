#include <iostream>
#include <vector>

using namespace std;

// Pre: v1 y v2 no están vacíos
// Post: Devuelve un vector con los elementos comunes de v1 y v2 (sin duplicados)
vector<int> elementos_comunes(const vector<int>& v1, const vector<int>& v2) {
  vector<int> resultado;

  for (size_t i = 0; i < v1.size(); ++i) {
    // I1 = El vector resultado contiene los elementos 
    //      comunes entre v1[0..i-1] y v2 sin duplicados
    for (size_t j = 0; j < v2.size(); ++j) {
      // I2 = !(v1[i] IN v2[0..j-1])
      if (v1[i] == v2[j]) {
        bool duplicado = false;
        size_t k = 0;
        while (!duplicado && k < resultado.size()) {
          // I3 = !duplicado && !(v1[i] IN resultado[0..k-1])
          if (resultado[k] == v1[i]) {
            duplicado = true;
          }
          k++;
        }
        // Añadir elemento comun (pero no duplicado)
        if (!duplicado) resultado.push_back(v1[i]);
        // Terminar el bucle intermedio
        break;
      }
    }
  }
  // Devolver resultado
  return resultado;
}

int main() {
  vector<int> v1 = {1, 2, 4, 5, 6, 3, 6};
  vector<int> v2 = {4, 9, 6, 7, 8, 2, 1, 2};
  
  // Pre: v1 y v2 no están vacíos
  vector<int> comunes = elementos_comunes(v1, v2);
  // Post: Devuelve un vector con los elementos comunes de v1 y v2 (sin duplicados)
  
  cout << "Elementos comunes: ";
  for (int num : comunes) {
    cout << num << " ";
  }
  cout << endl;
  
  return 0;
}
