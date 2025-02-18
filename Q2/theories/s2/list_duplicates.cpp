#include <iostream>
#include <list>

using namespace std;

void remove_duplicates(list<int>& lst) {
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    auto inner = next(it); // Start checking from the next element
    while (inner != lst.end()) {
      if (*it == *inner) {
        inner = lst.erase(inner); // Remove duplicate and update iterator
      } else {
        ++inner;
      }
    }
  }
}

int main() {
  list<int> l = {1, 2, 2, 3, 4, 2, 4, 5, 1};

  cout << "Original List: ";
  for (int x : l) {
    cout << x << " ";
  }
  cout << endl;

  remove_duplicates(l);

  cout << "After Removing Duplicates: ";
  for (int x : l) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
