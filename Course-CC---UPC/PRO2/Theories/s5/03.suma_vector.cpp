#include <vector>

using namespace std;

// PRE: -1 <= i < v.size()
// POST: Retorna la suma de v[0..i]
int suma_rec(const vector<int>& v, int i) {
  if (i < 0) {
    return 0;
  } else {
    // HI: retorna la suma de v[0..i-1]
    return suma_rec(v, i-1) + v[i];
  }
}

// PRE: True
// POST: Retorna la suma de los elementos de v
int suma(const vector<int>& v) {
  return suma_rec(v, v.size()-1);
}
