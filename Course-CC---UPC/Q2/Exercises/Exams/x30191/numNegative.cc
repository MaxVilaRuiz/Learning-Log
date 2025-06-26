#include "BinTree.hh"
#include "numNegative.hh"
#include "utils.hh"

int ampliacio(BinTree<string> t, int& count) {
    if (isNumber(t.value())) return mystoi(t.value());
    else {
        int res;
        int left = ampliacio(t.left(), count);
        int right = ampliacio(t.right(), count);

        if (t.value() == "+") {
            res = left + right;
            if (res < 0) count++;
        }
        else if (t.value() == "-") {
            res = left - right;
            if (res < 0) count++;
        }
        else {
            res = left * right;
            if (res < 0) count++;
        }  

        return res;
    }
}

int numNegative(BinTree<string> t) {
    if (isNumber(t.value())) return 0;
    else {
        int value = 0;
        ampliacio(t, value);
        return value;
    }
}