#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

bool findBST(const BT t, int x) {
	// Base case
  if (t.empty()) return false;
	// General case
  int value = t.value();
  if (x == value) {
    return true;
  } else if (x < value) {
    return findBST(t.left(), x);
  } else {
    return findBST(t.right(), x);
  }
}

BT insertBST(BT t, int x) {
	// Base case
	if (t.empty()) return BT(x);
	// General case
	if (x < t.value()) {
	  return BT(t.value(), insertBST(t.left(), x), t.right());
	} else {
		return BT(t.value(), t.left(), insertBST(t.right(), x));
	}
}

int main() {
	const int n = 100;
	// Unbalanced BST
	BT t;
	for (int i = 1; i <= n; i++) {
		insertBST(t, i);
	}
}


