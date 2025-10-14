#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
  list<int> l;
  string command;
  while (cin >> command) {
    if (command == "v.push_back(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending;
      l.push_back(val);
    } else if (command == "v.push_front(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; 
      l.push_front(val);
    } else if (command == "v.pop_front();") {
      if (0 < l.size()) l.pop_front();
    } else if (command == "v.pop_back();") {
        if (0 < l.size()) l.pop_back();
    } else if (command == "v.resize(") {
      int newsize;
      cin >> newsize;
      string ending;
      cin >> ending; 
      l.resize(newsize);
    } else if (command == "cout<<v[") {
      int index;
      cin >> index;
      string ending;
      cin >> ending; 

      if (index < ((l.size() - 1) / 2)) {
        auto it = l.begin();
        int i = 0;
        while (i != index) { it++; i++; }
        cout << *it << endl;
      }
      else {
        auto it = l.end(); 
        it--;
        int i = l.size() - 1;
        while (i != index) { it--; i--; }
        cout << *it << endl;
      }
    } else if (command == "cout<<v;") {
      auto it = l.begin();
      while (it != l.end()) {
        if (it != l.begin()) cout << ',';
        cout << *it;
        it++;
      }
      cout << endl;
    } else if (command == "v[") {
      int index;
      cin >> index;
      string mid;
      cin >> mid; // Això consumeix el "]="
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ";"
      if (index < ((l.size() - 1) / 2)) {
        auto it = l.begin();
        int i = 0;
        while (i != index) { it++; i++; }
        *it = val;
      }
      else {
        auto it = l.end(); 
        it--;
        int i = l.size() - 1;
        while (i != index) { it--; i--; }
        *it = val;
      }
    } else if (command == "//") {
      string comment;
      getline(cin, comment);
      cout << "//" << comment << endl;
    } else {
      cout << "Wrong command '" << command << "'" << endl;
      string discard;
      getline(cin, discard);
    }
  }
}