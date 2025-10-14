#include "BinTree.hh"
#include "numIncreasing.hh"

int ampliacio(BinTree<int> t, int last) {
    if (t.empty()) return 0;
    else {
        int val = 0;
        if (last < t.value()) val++;
        return val + ampliacio(t.left(), t.value()) + ampliacio(t.right(), t.value());
    }
}

int numIncreasing(BinTree<int> t) {
    return ampliacio(t.left(), t.value()) + ampliacio(t.right(), t.value());
}