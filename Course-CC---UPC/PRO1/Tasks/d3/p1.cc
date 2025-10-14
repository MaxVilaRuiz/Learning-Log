#include <iostream>
using namespace std;

// PRE: Seqüència de números naturals sense sentinella.
// POST: Es mostra una línia amb "SI" o "NO" depenent de la seqüència: 
//       serà "SI" si hi ha almenys 5 números de quatre dígits que tinguin 
//       el primer dígit igual que l'últim; serà "NO" en cas contrari.

int main() {
    int num;
    int comptador = 0;
    // Inv: comptador <= 5, essent la variable "comptador" la qual representa 
    //      el número de nombres de quatre xifres que tenen el primer i l'últim 
    //      dígit igual que es troben en la seqüència.
    while ((cin >> num) and (comptador < 5)) {
        int digit1, digit2;
        if ((num >= 1000) and (num <= 9999)) {
            digit1 = num % 10;
            num /= 1000;
            digit2 = num % 100;

            if (digit1 == digit2) comptador += 1; // Funció Fita (defineix el final del bucle).
        }
    }

    if (comptador >= 5) cout << "SI";
    else cout << "NO";
}