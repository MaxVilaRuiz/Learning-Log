#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

template <typename T>
void print_vector(vector<T> l) {
  for (typename vector<T>::iterator it = l.begin(); it != l.end(); it++) {
    cout << *it;
		if (it+1 != l.end()) cout << ",";
  }
  cout << endl;
}
BT insertBST(BT t, int x) {
	if (t.empty()) return BT(x);
	if (x <= t.value()) {
	  return BT(t.value(), insertBST(t.left(), x), t.right());
	} else {
		return BT(t.value(), t.left(), insertBST(t.right(), x));
	}
}
BT vector2BST(vector<int> v) {
  BT t;
  for (int i = 0; i < int(v.size()); i++) {
    t = insertBST(t, v[i]);
	}
  return t;
}
void inorderTraversal(BT t, vector<int> &v) {
	// Case base
  if (t.empty()) return;
	// Recursive case
  inorderTraversal(t.left(), v);
  v.push_back(t.value());
  inorderTraversal(t.right(), v);
}
vector<int> sortBST(vector<int> v) {
	// Creates a BST containing the elements of v
  BT t = vector2BST(v);
  vector<int> w;
	// Traverses in-order to recover sorted elements
  inorderTraversal(t, w);
  return w;
}
int main() {
  srand(time(NULL));
  const int n = 15;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = i;
	}
  random_shuffle(v.begin(), v.end());
	// Sort using a BST
  vector<int> w = sortBST(v);
	// Print sorted elements
  print_vector(w);
}