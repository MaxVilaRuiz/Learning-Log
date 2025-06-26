#include "bintree.hh"
#include "bintree-io.hh"

using namespace pro2;
using namespace std;

typedef BinTree<int> BT;

template<typename T>
void preorder(const BinTree<T> &t) {
  if (!t.empty()) {
    cout << t.value() << ' ';
    preorder(t.left());
    preorder(t.right());
  }
}

template<typename T>
void inorder(const BinTree<T> &t) {
  if (!t.empty()) {
    inorder(t.left());
    cout << t.value() << ' ';
    inorder(t.right());
  }
}

template<typename T>
void postorder(const BinTree<T> &t) {
  if (!t.empty()) {
    postorder(t.left());
    postorder(t.right());
    cout << t.value() << ' ';
  }
}

template<typename T>
void breadth_first(const BinTree<T> &t) {
  if (!t.empty()) {
    queue < BinTree < T >> q;
    q.push(t);
    while (!q.empty()) {
      BinTree<T> curr = q.front();
      q.pop();
      cout << curr.value() << ' ';
      if (!curr.left().empty()) {
        q.push(curr.left());
      }
      if (!curr.right().empty()) {
        q.push(curr.right());
      }
    }
  }
}
