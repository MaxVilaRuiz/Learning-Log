#include "tree.hh"
#include "tree-io.hh"

using namespace pro2;
using namespace std;

int main() {
  Tree<int> t1;
  // vacío
  Tree<int> t2(1); // sin hijos
  Tree<int> t3(2, { t1, t2, Tree<int>(-3), Tree<int>(0) }); // con 4 hijos
  cout << "t1" << endl << t1 << endl;
  cout << "t2" << endl << t2 << endl;
  cout << "t3" << endl << t3 << endl;
  cout << (t3.child(0).empty() ? "empty" : "non-empty") << endl;
  cout << t3.child(1).value() << endl;
  cout << t3.child(2).value() << endl;
  cout << t3.child(3).value() << endl;
  // clang-format off
  Tree<string> disk("C:", {
    Tree<string>("Windows", {
      Tree<string>("System32")
    }),
    Tree<string>("Program Files", {
      Tree<string>("Adobe"),
      Tree<string>("Microsoft")
    }),
    Tree<string>("Users", {
      Tree<string>("Groucho"),
      Tree<string>("Chicco"),
      Tree<string>("Harpo")
    })
  });
  // clang-format on
  cout << disk << endl;
}