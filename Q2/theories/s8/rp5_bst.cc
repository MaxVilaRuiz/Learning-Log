/*
 * Repaso1: Dado un árbol binario de búsqueda (BST),  
 *   imprime sus elementos en orden creciente. 
 */

#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

/*
 * Función auxiliar para recorrer el árbol (inorden)
 */
void print_sorted(const BinTree<int>& bst) {
  if (!bst.empty()) {
    print_sorted(bst.left());
    cout << bst.value() << " ";
    print_sorted(bst.right());
  }
}

int main() {
  // Constructors
  BinTree<int> t1;             // árbol vacío
  BinTree<int> t2(1, t1, t1);  //     1(,)
  BinTree<int> t3(3, t2, t1);  //   3(1,)
  BinTree<int> t4(6, t1, t1);  //           6(,)
  BinTree<int> t5(8, t1, t1);  //             8(,)
  BinTree<int> t6(7, t4, t5);  //         7(6,8)
  BinTree<int> bst(5, t3, t6); // 5(3(1,),7(6,8))

  // Or read from cin
  // BinTree<int> bst;
  // cin >> bst;         // Usa el operador >> definido en bintree-io.hh

	// Sorting number using a BST
  cout << "Sorted: "; 
  print_sorted(bst);
}
