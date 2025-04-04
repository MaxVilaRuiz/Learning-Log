#include "BinTree.hh"
#include "treeOfSumsOfAncestors.hh"

BinTree<int> ampliacio_pre(BinTree<int> t, int value) {
    if (t.empty()) return BinTree<int> ();
    else if (t.left().empty() && t.right().empty()) return BinTree<int> (t.value() + value);
    else return BinTree<int> (t.value() + value, ampliacio_pre(t.left(), t.value() + value), 
                            ampliacio_pre(t.right(), t.value() + value));
}

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
    return ampliacio_pre(t, 0);
}