#include <iostream>
#include <vector>

using namespace std;

// Pre: True
// Post: v no contiene duplicados
void eliminar_duplicados(vector<string>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    // I1 = v[0..i-1] no tiene duplicados 
    size_t j = i + 1;
    while (j < v.size()) { // Comprobar que los v[i+1 .. n-1] no contienen a v[i]
      // I2 = v[i] NOT IN v[i+1,..,j-1]
      if (v[i] == v[j]) {
        v.erase(v.begin() + j);
      } else {
        ++j;
      }
    }
  }
}


int main() {
  vector<string> v = 
    {"manzana", "pera", "uva", "manzana", "kiwi", "pera", "sandía"};
  
  // Pre: True
  eliminar_duplicados(v);
  // Post: v no contiene duplicados
  
  cout << "Vector sin duplicados:" << endl;
  for (const string& s : v) {
    cout << s << " ";
  }
  cout << endl;
  
  return 0;
}
