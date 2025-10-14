#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    stack<int> pila1;
    int elem = 0;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        pila1.push(elem);
    }

    stack<int> pila1_aux = pila1;
    stack<int> pila2;
    for (int i = 0; i < n; i++) {
        elem = pila1_aux.top();
        pila2.push(elem);
        pila1_aux.pop();
    }

    int i = 0;
    bool es_palindrom = true;
    while (i < n && es_palindrom) {
        if (pila1.top() == pila2.top()) {
            pila1.pop();
            pila2.pop();
        }
        else es_palindrom = false;
        i++;
    }

    if (es_palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}