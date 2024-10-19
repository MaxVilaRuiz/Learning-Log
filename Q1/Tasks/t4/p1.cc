// X62652

#include <iostream>
using namespace std;

// Pre: L'entrada consisteix en zero o més seqüències autodelimitades 
//      (acabades en "0101") expressades en binari en què cada bit es troba 
//      duplicat i la seqüència "01" s'utilitza per a indicar la separació de 
//      dos números dins la seqüència.
// Post: La sortida consisteix en mostrar un nombre enter per cada seqüència 
//       autodelimitada. El nombre ha de representar la suma de la llista de 
//       números representats per la seqüència en qüestió.

int main() {
    char c1, c2;
    int num2 = 0, comptador = 0, num10 = 0;
    int digit = 1;
    int n1, bit, posicio;
    while (cin >> c1 >> c2) {

        if (c1 == c2) {
            if (c1 == '1') n1 = 1;
            else n1 = 0;

            num2 *= 10;
            num2 += n1;
            comptador = 0;
        }
        else if ((c1 == '0') and (c2 == '1')) {
            posicio = 0;
            // Inv: Com que un nombre no pot tenir menys de zero bits/dígits, 
            //      la variable "num2" tampoc els tindrà mai ((num >= 0) == true).
            while (num2 > 0) {
                bit = num2 % 10;
                if (bit == 1) {
                    for (int i = 0; i < posicio; i++) digit *= 2;
                    num10 += digit;
                    digit = 1;
                }

                posicio++;
                num2 /= 10; // Funció Fita.
            }

            num2 = 0;
            comptador++;
        }

        if (comptador == 2) {
            cout << num10 << endl;
            num10 = 0;
            comptador = 0;
        }
    }
}