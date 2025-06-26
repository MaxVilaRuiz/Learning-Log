/*
 * Repaso0: Dado un árbol binario de enteros, computa la media de sus elementos. 
 */

#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

int bt_sum(const BinTree<int>& t) {
  if (t.empty()) return 0;
  return t.value() + bt_sum(t.left()) + bt_sum(t.right());
}

int bt_size(const BinTree<int>& t) {
  if (t.empty()) return 0;
  return 1 + bt_size(t.left()) + bt_size(t.right());
}

double bt_average(BinTree<int> t) {
  if (t.empty()) return 0.0; // Evitar división por cero
  //
  // TODO: Puedes hacerlo con solo 1 recorrido del bintree ???
  //
  return double(bt_sum(t)) / bt_size(t);
}

int main() {
  // Constructors
  BinTree<int> t1;            // t1 es un árbol vacı́o
  BinTree<int> t2(8, t1, t1); // t2 =     8(,)
  BinTree<int> t3(3, t2, t1); // t3 =   3(8,)
  BinTree<int> t4(2, t1, t1); // t4 =              2
  BinTree<int> t5(1, t1, t4); // t5 =           1(,2)
  BinTree<int> t6(7, t5, t2); // t6 =         7(1(,2),8)
  BinTree<int> t7(5, t3, t6); // t7 = 5(3(8,),7(1(,2),8))

	// Average
  cout << "The average is: " << bt_average(t7) << endl;
}
