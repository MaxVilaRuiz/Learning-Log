/*
 * Ejercicio 1: Mostrar la raíz
 *   Implementa void mostra_arrel() const que imprima el valor 
 *   de la raíz si el árbol no está vacío. Si lo está, imprime "Arbre buit".
 */

#include <string>
#include <iostream>
#include "ArbreN.hh"

void mostra_arrel(ArbreNari<string>& arbre) {
  if (!arbre.es_buit())
    cout << arbre.arrel() << endl;
  else
    cout << "Arbre buit" << endl;
}
