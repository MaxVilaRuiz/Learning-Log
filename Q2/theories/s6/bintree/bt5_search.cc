#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

bool bt_search(BT t, int key) {
  // TODO
}

int main() {
  // Constructors
  BT t1;            // t1 es un árbol vacı́o
  BT t2(8, t1, t1); // t2 =    8(,) = 8 (arbol con 8 en la raı́z
                    //                   y dos subárboles vacı́os)
  BT t3(3, t2, t1); // t3 =   3(8,)
  BT t4(2, t1, t1); // t4 =              2
  BT t5(1, t1, t4); // t5 =           1(,2)
  BT t6(7, t5, t2); // t6 =         7(1(,2),8)
  BT t7(5, t3, t6); // t7 = 5(3(8,),7(1(,2),8))

	// Search for a value
  cout << "The key=10 is in the BinTree? " << bt_search(t7,10) << endl;
}
