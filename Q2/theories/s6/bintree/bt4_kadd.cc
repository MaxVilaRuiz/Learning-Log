#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

BT bt_kadd(const BT& t, int k) {
  // Base case
  if (t.empty()) {
    return BT();
  }
  // General case
  auto left_kadded = bt_kadd(t.left(),k);
  auto rigth_kadded = bt_kadd(t.right(),k);
  return BT(t.value() + k,
            left_kadded,rigth_kadded);
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

	// Print
  cout << t7 << endl;
	// K-add
  BT t8 = bt_kadd(t7,2);
  cout << t8 << endl;
}