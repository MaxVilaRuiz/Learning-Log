#include <iostream>
#include <vector>
using namespace std;

// Pre: L'entrada consisteix en un vector i un nombre natural, el 
//      qual representa el nombre de files i columnes del vector 
//      si aquest es representés en forma de matriu quadràtica.
// Post: La funció retorna true si el vector és doblement 
//       estocàstica, altrament retorna false. 
bool doubly_stochastic(const vector<int>& v, int cols) {
    int sum = 0, count = 0;

    // Per a les files:
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        count++;
        if (count == cols) {
            if (sum == 10) {
                sum = 0;
                count = 0;
            }
            else return false;
        }
    }

    // Per a les columnes:
    int pos = 0;
    while (count < cols) {
        sum += v[pos];
        pos += cols;
        if (pos > v.size()) {
            if (sum == 10) {
                sum = 0;
                pos = count + 1;
                count++;
            }
            else return false;
        }
    }

    return true;
}


// Pre: L'entrada consisteix en un nombre natural 'n' que
//      representa el nombre de seqüències que s'introduiran 
//      i la quantitat de números que es demanaran per cada seqüència.
// Post: Es mostra "true" si la seqüència de seqüències és doblement 
//       estocàstica, altrament es mostrarà "false".
int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n*n);
        for (int i = 0; i < v.size(); i++) {
            cin >> v[i];
        }

        if (doubly_stochastic(v, n)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}