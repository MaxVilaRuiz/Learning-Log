#include <iostream>
#include <map>
#include <string>

using namespace std;

void print_map(ostream &os, map<string, int> m) {
  os << "{";
  bool printcomma = false;
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    if (printcomma)
      os << ", ";
    printcomma = true;
    os << it->first << ":" << it->second;
  }
  os << "}";
  os << endl;
}

ostream &operator<<(ostream &os, map<string, int> m) {
  print_map(os, m);
  return os;
}

int main() {
  map<string, int> age;

  // Inserciones con insert()
  age.insert({"Laura", 42});
  age.insert({"Guille", 50});
  age.insert({"Sonia", 16});
  age.insert({"Jose", 55});

  // Accesos con at()
  cout << age.at("Sonia") << endl;
  cout << age.at("Jose") << endl;
  cout << age.at("Guille") << endl;
  cout << age.at("Laura") << endl;

  // Modificaciones con find()
  auto it = age.find("Jose");
  if (it != age.end()) it->second = 56;

  it = age.find("Guille");
  if (it != age.end()) it->second++;

  // Manejo de inserción si la clave no existe
  if (age.find("Nuria") == age.end()) {
    age.insert({"Nuria", 1});
  } else {
    age.find("Nuria")->second++;
  }

  // Salida final
  cout << age;
}
