#include "BinTree.hh"
#include "postorderTree.hh"
#include <stack>

BinTree<int> res(BinTree<int> t, int& value) {
    if (t.left().empty() && t.right().empty()) {
        return BinTree<int> (value);
    }
    else if (t.left().empty()) {
        BinTree<int> t_right = res(t.right(), value);
        value++;
        return BinTree<int> (value, BinTree<int> (), t_right);
    }
    else if (t.right().empty()) {
        BinTree<int> t_left = res(t.left(), value);
        value++;
        return BinTree<int> (value, t_left, BinTree<int> ());
    }
    else { // Full Tree
        BinTree<int> t_left = res(t.left(), value);
        value++;
        BinTree<int> t_right = res(t.right(), value);
        value++;
        return BinTree<int> (value, t_left, t_right);
    }
}

BinTree<int> postorderTree(BinTree<int> t) {
    int value = 1;
    return res(t, value); 
}