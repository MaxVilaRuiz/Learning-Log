/*
 * Ejercicio 1: Crear y mostrar un árbol sencillo
 *   Construye un árbol binario con los enteros {1, 2, 3} 
 *   donde 1 es la raíz, 2 el hijo izquierdo y 3 el derecho. Imprime la raíz.
 */

#include "Arbre.hh"
#include <iostream>

using namespace std;

int main() {
  Arbre<int> a1, a2, a;
  Arbre<int> empty1, empty2, empty3, empty4;
  
  a1.plantar(2, empty1, empty2);
  a2.plantar(3, empty3, empty4);
  a.plantar(1, a1, a2);

  cout << "Raíz del árbol: " << a.arrel() << endl;
}
