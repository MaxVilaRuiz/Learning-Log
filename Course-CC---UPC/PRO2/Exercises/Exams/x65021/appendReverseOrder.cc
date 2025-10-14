#include "appendReverseOrder.hh"
#include <stack>
using namespace std;

void appendReverseOrder(list<int> &l) {
    stack<int> aux;
    for (auto it = l.begin(); it != l.end(); it++) {
        aux.push(*it);
    }

    int fita = aux.size();
    for (int i = 0; i < fita; i++) {
        l.push_back(aux.top());
        aux.pop();
    }
}