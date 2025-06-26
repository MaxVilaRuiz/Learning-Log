/*
 * Repaso 2: Escribe una función que reciba dos listas ordenadas 
 *   de enteros l1 y l2, y devuelva una nueva lista ordenada con 
 *   los elementos que aparecen en ambas listas (intersección).
 *   No exiten elementos repetidos.
 *   Usa std::list<int> y sus iteradores.
 */

#include <iostream>
#include <list>

using namespace std;

list<int> interseccion(const list<int>& l1, const list<int>& l2) {
  list<int> res;
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  while (it1 != l1.end() && it2 != l2.end()) {
    if (*it1 < *it2) {
      ++it1;
    } else if (*it1 > *it2) {
      ++it2;
    } else {
      res.push_back(*it1);
      ++it1;
      ++it2;
    }
  }
  return res;
}

int main() {
  list<int> l1 = {1, 2, 4, 6};
  list<int> l2 = {2, 3, 4, 5};

  list<int> res = interseccion(l1, l2);

  for (int x : res) cout << x << " ";
  cout << endl;

  return 0;
}
