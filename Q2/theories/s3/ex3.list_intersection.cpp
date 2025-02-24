#include <iostream>
#include <list>

using namespace std;

// Pre: l1 y l2 no están vacías
// Post: resultado contiene los elementos comunes de l1 y l2 sin duplicados
list<int> elementos_comunes(const list<int>& l1, const list<int>& l2) {
  list<int> resultado;

  for (auto it1 = l1.begin(); it1 != l1.end(); ++it1) {
    // I1 = La lista resultado contiene los elementos 
    //      comunes entre l1[0..it1-1] y l2 sin duplicados
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2) {
      // I2 = !(*it1 IN l2[0..it2-1])
      if (*it1 == *it2) {
        bool duplicado = false;
        auto it_res = resultado.begin();
        while (!duplicado && it_res != resultado.end()) {
          // I3 = !duplicado && !(*it1 IN resultado[0..it_res-1])
          if (*it_res == *it1) {
            duplicado = true;
          }
          it_res++;
        }
        // Añadir elemento comun (pero no duplicado)
        if (!duplicado) resultado.push_back(*it1);
        // Terminar el bucle intermedio
        break;
      }
    }
  }

  // Devolver resultado
  return resultado;
}

int main() {
  list<int> l1 = {1, 2, 4, 5, 6, 3, 6};
  list<int> l2 = {4, 9, 6, 7, 8, 2, 1, 2};

  // Pre: l1 y l2 no están vacías
  list<int> comunes = elementos_comunes(l1, l2);
  // Post: resultado contiene los elementos comunes de l1 y l2 sin duplicados
  
  cout << "Elementos comunes: ";
  for (int num : comunes) {
    cout << num << " ";
  }
  cout << endl;
  
  return 0;
}
