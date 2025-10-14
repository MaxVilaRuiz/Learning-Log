#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

#include <iostream>
using namespace std;

/**
 * @brief Retorna l'arbre de mides de `t`.
 *
 * L'arbre de mides és un arbre binari amb la mateixa forma que `t` però a on cada valor conté la
 * quantitat total de nodes del subarbre que penja de la mateixa posició a `t`.
 *
 * @param t L'arbre binari original.
 *
 * @returns L'arbre de mides de `t`.
 */
BinTree<int> tree_of_sizes(BinTree<int> t) {
    if (t.empty()) return t;

    else if (t.left().empty() && t.right().empty()) return BinTree<int>(1);

    else if (t.left().empty()) return BinTree<int>(1 + tree_of_sizes(t.right()).value(), BinTree<int>(), tree_of_sizes(t.right()));

    else if (t.right().empty()) return BinTree<int>(1 + tree_of_sizes(t.left()).value(), tree_of_sizes(t.left()), BinTree<int>());

    return BinTree<int>(1 + tree_of_sizes(t.left()).value() + tree_of_sizes(t.right()).value(), 
                        tree_of_sizes(t.left()), tree_of_sizes(t.right()));
}