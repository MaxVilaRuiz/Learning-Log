#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
 * Example 1: list<int> printer
 */
void print_list(list<int> l) {
  for (list<int>::iterator it = l.begin();
       it != l.end();
       it++) { 
    cout << *it;
		cout << ",";
  }
  cout << endl;
}

/*
 * Example 2: Generic list printer
 */
template <typename T> 
void print_list(list<T> l) {
  typename list<T>::iterator it = l.begin();
  while (it != l.end()) {
    cout << *it;
		cout << ",";
    it++;
  }
  cout << endl;
}

/*
 * Example 3: Copy vs Value
 */
void access_list_val(list<string> l) {
	l.push_front("100");
}
void access_list_ref(list<string>& l) {
	l.push_front("666");
}

/*
 * General List Usage
 */
int main() {
  /*
   * List Accessors
   */
  list<string> l;
  l.push_back("a");                      // l: a
  l.push_front("b");                     // l: b,a
  l.push_back("c");                      // l: b,a,c
  l.pop_front();                         // l: a,c
  l.pop_back();                          // l: a
  l.push_front("b");                     // l: b,a
  l.push_back("c");                      // l: b,a,c
  l.push_back("d");                      // l: b,a,c,d

  /*
   * Iterators
   */
  list<string>::iterator it = l.begin(); // l: (b),a,c,d
  it++;                                  // l: b,(a),c,d
  it++;                                  // l: b,a,(c),d
  it--;                                  // l: b,(a),c,d
  it++;                                  // l: b,a,(c),d
  it++;                                  // l: b,a,c,(d)
  it++;                                  // l: b,a,c,d,()
  it = l.begin();                        // l: (b),a,c,d
  cout << (it == l.end()) << endl;       // output: 0
  cout << *it << endl;                   // output: b
  it = l.end();                          // l: b,a,c,d,()
  cout << (it == l.end()) << endl;       // output: 1
  cout << l.size() << endl;              // output: 4
  cout << l.empty() << endl;             // output: 0
  it = l.begin();                        // l: (b),a,c,d
  it++;                                  // l: b,(a),c,d
  it++;                                  // l: b,a,(c),d
  l.insert(it, "e");                     // l: b,a,e,(c),d
  it--;                                  // l: b,a,(e),c,d
  it--;                                  // l: b,(a),e,c,d
  it = l.erase(it);                      // l: b,(e),c,d

  // Print contents
  print_list(l); 

  /*
   * Copy vs Value
   */
  // Access list (value)
  access_list_val(l); print_list(l);
  // Access list (reference)
  access_list_ref(l); print_list(l);
}