#include <iostream>
using namespace std;

// Pre: L'entrada consisteix en una paraula o número que
//      representa l'expressió que cal avaluar.
// Post: La funció retorna un nombre enter que representa el
//       resultat d'avaluar la/les entrada/es de la funció (cal
//       calcular el màx / mín de múltiples expressions o únicament
//       retornar el valor d'un enter).
int mmeval() {
    string expression;
    cin >> expression;
    if ((expression == "max") or (expression == "min")) {
        int e1 = mmeval();
        int e2 = mmeval();
        if(expression == "max") {
            if (e1 > e2) return e1;
            else return e2;
        }
        else {
            if (e1 < e2) return e1;
            else return e2;
        }
    }
    else return stoi(expression);
}

// Pre: L'entrada consisteix en un nombre natural que representa 
//      el número de vegades que cal cridar a la funció "mmeval()".
// Post: Mostra el valor retornar per la funció "mmeval()" 
//       per a cadascuna de les 'n' expressions.
int main() {
    int n;
    cin >> n;
    // Inv: 'n' mai serà menor a zero (n >= 0).
    while (n > 0) {
        cout << mmeval() << endl;
        n--;
    }
}