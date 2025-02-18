#include <iostream>
#include <list>

using namespace std;

// Function to merge two sorted lists into a third sorted list
list<int> mergeSortedLists(
    const list<int> &list1, const list<int> &list2) {
  list<int> merged;
  auto it1 = list1.begin();
  auto it2 = list2.begin();

  // Merge both lists while both have elements
  while (it1 != list1.end() && it2 != list2.end()) {
    if (*it1 < *it2) {
      merged.push_back(*it1);
      ++it1;
    } else {
      merged.push_back(*it2);
      ++it2;
    }
  }

  // Add remaining elements from list1
  while (it1 != list1.end()) {
    merged.push_back(*it1);
    ++it1;
  }

  // Add remaining elements from list2
  while (it2 != list2.end()) {
    merged.push_back(*it2);
    ++it2;
  }

  return merged;
}
int main() {
  list<int> list1 = {1, 3, 5};
  list<int> list2 = {2, 4, 6};

  list<int> merged = mergeSortedLists(list1,list2);

  cout << "Merged List: ";
  for (int x : merged) {
      cout << x << " ";
  }
  cout << endl;

  return 0;
}
