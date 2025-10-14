#include <iostream>
#include <map>
#include <string>

using namespace std;

void print_map(ostream &os, map<string, int> m) {
  os << "{";
  bool printcomma = false;
  for (map<string, int>::iterator it = m.begin(); 
       it != m.end(); 
       it++) {
    if (printcomma) os << ", ";
    printcomma = true;
    os << it->first << ":" << it->second;
  }
  os << "}";
  os << endl;
}

ostream& operator<<(ostream& os, map<string, int> m) {
  print_map(os, m);
  return os;
}

int main() {
  map<string, int> age;
  age["Laura"] = 42;             // {Laura:42}
  age["Guille"] = 50;            // {Guille:50,Laura:42}
  age["Sonia"] = 16;             // {Guille:50,Laura:42,Sonia:16}
  age["Jose"] = 55;              // {Guille:50,Jose:55,Laura:42,Sonia:16}
  cout << age["Sonia"] << endl;  // output: 16
  cout << age["Jose"] << endl;   // output: 55
  cout << age["Guille"] << endl; // output: 50
  cout << age["Laura"] << endl;  // output: 42
  // Cumpleaños
  age["Jose"] = 56; // {Guille:49,Jose:56,Laura:42,Sonia:16}
  age["Guille"]++;  // {Guille:51,Jose:56,Laura:42,Sonia:16}
  // Un acceso a una posicioón no inicializada lo inicializa
  age["Nuria"]++;   // {Guille:51,Jose:56,Laura:42,Nuria:1,Sonia:16}
	// Salida en standard output
	cout << age;
}