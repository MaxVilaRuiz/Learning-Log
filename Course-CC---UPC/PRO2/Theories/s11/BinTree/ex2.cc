/*
  * Ejercicio 2: Obtener la altura de un árbol
  *   Implementa una función altura que devuelva 
  *   la altura de un árbol binario.
  */

#include "Arbre.hh"

int altura(Arbre<int>& a) {
  // Base case
  if (a.es_buit()) return 0;
  // General case
  Arbre<int> fe, fd;
  a.fills(fe, fd);
  int h = 1 + max(altura(fe), altura(fd));
  return h;
}

