#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

#include <iostream>
using namespace std;

/**
 * @brief Retorna l'arbre de sumes de `t`.
 *
 * L'arbre de sumes és un arbre binari amb la mateixa forma de `t` però a on cada valor conté la
 * suma dels valors del subarbre que penja de la mateixa posició a `t`.
 *
 * @param t L'arbre binari original.
 *
 * @returns L'arbre de sumes de `t`.
 */
BinTree<int> tree_of_sums(BinTree<int> t) {
    if (t.empty()) return t;
    else if (t.left().empty() && t.right().empty()) return t;

    else if (t.left().empty()) 
        return BinTree<int>(t.value() + tree_of_sums(t.right()).value(), BinTree<int>(), tree_of_sums(t.right()));

    else if (t.right().empty())
        return BinTree<int>(t.value() + tree_of_sums(t.left()).value(), tree_of_sums(t.left()), BinTree<int>());

    return BinTree<int>(t.value() + tree_of_sums(t.left()).value() + tree_of_sums(t.right()).value(), 
                        tree_of_sums(t.left()), tree_of_sums(t.right()));
}