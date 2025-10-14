#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  set<string> s;
  s.insert("Laura");                 // s: {Laura}
  s.insert("Guille");                // s: {Guille,Laura}
  s.insert("Sonia");                 // s: {Guille,Laura,Sonia}
	s.insert("Sonia");                 // s: {Guille,Laura,Sonia}
  s.insert("Nuria");                 // s: {Guille,Laura,Nuria,Sonia}
  cout << s.count("Guille") << endl; // output: 1
  cout << s.count("Manel") << endl;  // output: 0
}