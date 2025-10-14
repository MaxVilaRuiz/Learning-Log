#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Función para calcular la unión de dos conjuntos
set<int> union_conjuntos(const set<int>& A, const set<int>& B) {
  set<int> union_set = A; // Copiamos A en el resultado
  union_set.insert(B.begin(), B.end()); // Insertamos todos los elementos de B
  return union_set;
}

// Función para calcular la intersección de dos conjuntos
set<int> interseccion_conjuntos(const set<int>& A, const set<int>& B) {
  set<int> interseccion;
  
  for (int num : A) {
    if (B.find(num) != B.end()) { // Si el número está en B
      interseccion.insert(num);
    }
  }
  
  return interseccion;
}

int main() {
  set<int> A = {1, 2, 3, 4, 5};
  set<int> B = {3, 4, 5, 6, 7};

  set<int> union_res = union_conjuntos(A, B);
  set<int> interseccion_res = interseccion_conjuntos(A, B);

  // Mostrar Unión
  cout << "Unión: ";
  for (int num : union_res) {
    cout << num << " ";
  }
  cout << endl;

  // Mostrar Intersección
  cout << "Intersección: ";
  for (int num : interseccion_res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
