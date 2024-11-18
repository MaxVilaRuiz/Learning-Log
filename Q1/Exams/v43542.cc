#include <iostream>
using namespace std;

/**
* @pre c1, c2, c3 en {A, 2, 3, ..., 8, 9, 0, J, Q, K}
* @post Retorna "Trio d'Asos!", "Trio", "Parella", o 
*       "Totes les cartes diferents" segons c1, c2 i c3.
*/
string poker_hand(char c1, char c2, char c3) {
    string res;
    if (c1 == 'A' and c1 == c2 and c2 == c3) res = "Trio d'Asos!";
    else if (c1 == c2 and c2 == c3) res = "Trio";
    else if (c1 == c2 or c1 == c3 or c2 == c3) res = "Parella";
    else res = "Totes les cartes diferents";

    return res;
}

int main() {
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    string estat = poker_hand(c1, c2, c3);
    cout << estat << endl;
}