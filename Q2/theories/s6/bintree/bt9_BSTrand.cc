#include <algorithm>    // std::random_shuffle
#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

BT insertBST(BT t, int x) {
	if (t.empty()) return BT(x);
	if (x <= t.value()) {
	  return BT(t.value(), insertBST(t.left(), x), t.right());
	} else {
		return BT(t.value(), t.left(), insertBST(t.right(), x));
	}
}
BT vector2BST(vector<int> v) {
  random_shuffle(v.begin(), v.end());
  BT t;
  for (int i = 0; i < int(v.size()); i++) {
    t = insertBST(t, v[i]);
	}
  return t;
}
int heightTree(BT t) {
  if (t.empty()) return 0;
  return 1 + max(heightTree(t.left()), heightTree(t.right()));
}
int main() {
  srand(time(NULL));
  const int n = 1024;
	int tests = 10;
  while (tests > 0) {
		--tests;
		// Generate random numbers
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = i;
		}
    BT t = vector2BST(v);
    // Print height of the BST
    cout << heightTree(t) << endl;
  }
}