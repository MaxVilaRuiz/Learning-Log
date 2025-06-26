/*
 * Repaso 3: Escribe una función que reciba dos vectores ordenados 
 *   de enteros v1 y v2, y devuelva un nuevo vector ordenado con 
 *   los elementos que aparecen en ambos vectores (intersección).
 *   Usa std::vector<int> e índices.
 */

 #include <iostream>
 #include <vector>
 
 using namespace std;
 
vector<int> interseccion(const vector<int>& v1, const vector<int>& v2) {
  vector<int> res;
  int i = 0, j = 0;
  while (i < v1.size() && j < v2.size()) {
    if (v1[i] < v2[j]) {
      ++i;
    } else if (v2[j] < v1[i]) {
      ++j;
    } else {
      res.push_back(v1[i]); // v1[i] == v2[j]
      ++i;
      ++j;
    }
  }
  return res;
}
 
int main() {
  vector<int> v1 = {1, 2, 4, 6};
  vector<int> v2 = {2, 3, 4, 5};

  vector<int> res = interseccion(v1, v2);

  for (int x : res) cout << x << " ";
  cout << endl;

  return 0;
}
