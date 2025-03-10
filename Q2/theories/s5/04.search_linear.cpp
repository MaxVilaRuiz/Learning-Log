#include <iostream>
#include <vector>

using namespace std;

// PRE: 0 <= i <= v.size(), 0 <= j < v.size(), v está ordenado crecientemente.
// POST: Si x IN v[i..j] => Devuelve p tq. v[p] = x
//       Si x NOT IN v[i..j] => Devuelve -1 
int busqueda_rec(const vector<int>& v, int x, int i, int j) {
  if (i > j) {
    return -1;
  } else if (v[i] == x) {
    return i; 
  } else {
    // HI: Si x IN v[i+1..j] => Devuelve p tq. v[p] = x
    //     Si x NOT IN v[i+1..j] => Devuelve -1 
    return busqueda_rec(v,x,i+1,j);
  }
}

// PRE: v.size() > 0 y v está ordenado crecientemente.
// POST: Si x IN v => Devuelve p tq. v[p] = x
//       Si x NOT IN v => Devuelve -1 
int busqueda(const vector<int>& v, int x) {
  return busqueda_rec(v, x, 0, v.size()-1);
}

// Función de prueba en el main
int main() {
  vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};

  cout << "Prueba de cerca:\n";
  cout << "Buscar 5 en v: " << busqueda(v, 5) << " (esperado: 2)\n";
  cout << "Buscar 10 en v: " << busqueda(v, 10) << " (esperado: -1)\n";

  return 0;
}


