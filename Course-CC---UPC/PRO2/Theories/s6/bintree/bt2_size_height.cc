#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

// PRE: True
// POST: Returns the height of the tree t
int bt_heigh(BT t) { 
  // Base case
  if (t.empty()) {
    return 0;
  }
  // General Case
  //   HI1: bt_heigh(t.left()) return the height 
  //        of the subtree t.left()
  //   HI2: bt_heigh(t.right()) return the height 
  //        of the subtree t.right()
  return max(bt_heigh(t.left()),
             bt_heigh(t.right())) + 1;
}

// PRE: t is any binary tree
// POST: Returns the number of nodes contained in t
int bt_nodes(BT t) {
  // Base case
  if (t.empty()) {
    return 0;
  }
  // General case
  //   HI1: bt_nodes(t.left()) returns the number
  //        of nodes contained in t.left()
  //   HI2: bt_nodes(t.right()) returns the number
  //        of nodes contained in t.right()
  return 1 + bt_nodes(t.left()) + bt_nodes(t.right());
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

	// Compute height
	//cout << "The height of the BinTree is " << bt_heigh(t7) << endl;
	// Compute number of nodes
  cout << "The BinTree has " << bt_nodes(t7) << " nodes\n";
}
