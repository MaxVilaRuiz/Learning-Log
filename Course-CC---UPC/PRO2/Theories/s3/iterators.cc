#include <iostream>
#include <list>
using namespace std;


int main() {
list<int> L {1, 2, 3, 4, 5};

// Iterate over the elements of a list (for loop)
for (list<int>::iterator it = L.begin(); it != L.end(); it++) { 
    cout << *it << endl;
}

// Iterate over the elements of a list (while loop)
list<int>::iterator it = L.begin(); 
while (it != L.end()) {
    cout << *it << endl;
    it++; 
}

// Using auto (auto infers the type of the variable)
for (auto it = L.begin(); it != L.end(); it++) {
  cout << *it << endl;
}

// Range-based Loop (>= C++11)
for (int x : L) {
  cout << x << endl;
}

return 0;
}