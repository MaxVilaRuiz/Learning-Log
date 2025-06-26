#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> encontrar_duplicados(const vector<int>& numeros) {
  set<int> vistos;      // Almacena números únicos
  set<int> duplicados;  // Almacena números que aparecen más de una vez

  for (int num : numeros) {
    if (vistos.find(num) != vistos.end()) {
      duplicados.insert(num);
    } else {
      vistos.insert(num);
    }
  }

  return duplicados;
}

int main() {
  vector<int> numeros = {3, 5, 2, 8, 3, 7, 5, 10, 2, 2};

  set<int> duplicados = encontrar_duplicados(numeros);

  cout << "Números duplicados: ";
  for (int num : duplicados) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
