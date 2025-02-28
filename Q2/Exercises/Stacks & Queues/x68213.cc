#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Book {
    string title = "";
    int category = 0;
};

int main() {
    int n;
    cin >> n;
    vector< stack<string> > v (n);

    int option = 0;
    while (cin >> option && option != -4) {
        if (option == -1) {
            Book llibre;
            cin >> llibre.title >> llibre.category;
            v[llibre.category - 1].push(llibre.title); 
        }
        else if (option == -2) {
            int amount = 0, pila = 0;
            cin >> amount >> pila;
            for (int i = 0; i < amount; i++) {
                v[pila - 1].pop();
            }
        }
        else if (option == -3) {
            int pila = 0;
            cin >> pila;
            stack<string> aux_stack = v[pila - 1];

            cout << "Pila de la categoria " << pila << endl;
            while (aux_stack.size() != 0) {
                cout << aux_stack.top() << endl;
                aux_stack.pop();
            }
            cout << endl;
        }
    }

    return 0;
}