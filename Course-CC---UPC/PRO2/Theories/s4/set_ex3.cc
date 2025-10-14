#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  set<int> A = {1, 2, 3, 4, 5};
  set<int> B = {3, 4, 5, 6, 7};

  // Vectores para almacenar los resultados
  vector<int> union_res(A.size() + B.size());
  vector<int> interseccion_res(min(A.size(), B.size()));

  // Calcular unión
  auto it_union = set_union(A.begin(), A.end(), B.begin(), B.end(), union_res.begin());
  union_res.resize(it_union - union_res.begin()); // Ajustar tamaño real

  // Calcular intersección
  auto it_inter = set_intersection(A.begin(), A.end(), B.begin(), B.end(), interseccion_res.begin());
  interseccion_res.resize(it_inter - interseccion_res.begin());

  // Mostrar Unión
  cout << "Unión: ";
  for (int num : union_res) cout << num << " ";
  cout << endl;

  // Mostrar Intersección
  cout << "Intersección: ";
  for (int num : interseccion_res) cout << num << " ";
  cout << endl;

  return 0;
}
