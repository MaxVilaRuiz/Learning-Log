#include <iostream>
using namespace std;

#include "tree-io.hh"
#include "eval.hh"
using namespace pro2;

/**
 * @brief Avalua un arbre no buit que representa una expressió Booleana.
 *
 * L'expressió és sobre l'1 (true) i el 0 (fals) i els operadors 
 * 'and', 'or', i 'not'.
 *
 * @pre L'arbre és no buit i l'expressió és correcta, és a dir, els operands
 * 'and' i 'or' tenen més d'un operand, i l'operador 'not' en té només 1.
 *
 * @param t Arbre que representa l'expressió.
 * @return Resultat de l'avaluació de l'expressió.
 */
bool evaluate(Tree<string> t) {
    bool res;
    if (t.value() == "and") {
        res = true;
        for (int i = 0; i < t.num_children(); i++) {
            if (t.child(i).value() == "and" || t.child(i).value() == "or" ||
                t.child(i).value() == "not") {
                res = res && evaluate(t.child(i));
            }
            else res = res && bool(stoi(t.child(i).value()));
        }
    }   
    else if (t.value() == "or") {
        res = false;
        for (int i = 0; i < t.num_children(); i++) {
            if (t.child(i).value() == "and" || t.child(i).value() == "or" ||
                t.child(i).value() == "not") {
                res = res || evaluate(t.child(i));
            }
            else res = res || bool(stoi(t.child(i).value()));
        }
    }
    else {
        if (t.child(0).value() == "and" || t.child(0).value() == "or" ||
                t.child(0).value() == "not") {
            res = !evaluate(t.child(0));
        }
        else res = !bool(stoi(t.child(0).value()));
    }
    return res;
}

int main() {
    Tree<string> t;
    while (cin >> t) {
        cout << evaluate(t) << endl;
    }
}