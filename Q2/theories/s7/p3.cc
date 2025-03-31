#include <iostream>
#include <vector>
#include "bintree.hh"
#include "bintree-io.hh"
using namespace std;
using namespace pro2;

void sort_tree(const BinTree<int>& t) {
    if (t.empty()) return;
    sort_tree(t.left());
    cout << t.value() << ' ';
    sort_tree(t.right());
}