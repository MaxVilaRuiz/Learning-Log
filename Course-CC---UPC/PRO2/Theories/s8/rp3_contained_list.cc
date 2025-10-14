/*
 * Repaso 4: Escribe una función que, dadas dos listas ordenadas l1 y l2, 
 *   determine si todos los elementos de l1 están en l2. 
 *   Usa std::list<int> y sus iteradores.
 */

#include <iostream>
#include <list>

using namespace std;

bool contenida(const list<int>& l1, const list<int>& l2) {
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  while (it1 != l1.end() && it2 != l2.end()) {
    if (*it1 < *it2) {
      return false; // elemento de l1 no está en l2
    } else if (*it2 < *it1) {
      ++it2;
    } else {
      ++it1;
      ++it2;
    }
  }
  return it1 == l1.end(); // todos los de l1 han sido encontrados
}

int main() {
  list<int> l1 = {2, 3};
  list<int> l2 = {1, 2, 3, 4};
  cout << (contenida(l1, l2) ? "sí" : "no") << endl; // debe imprimir "sí"

  l1 = {2, 5};
  cout << (contenida(l1, l2) ? "sí" : "no") << endl; // debe imprimir "no"

  return 0;
}


