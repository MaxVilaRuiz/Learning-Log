#include <iostream>
using namespace std;

// Precondició: entrada d'un número positiu major que 0 i menor que 10000 (num > 0 && num < 10000).
// Postcondició: mostrar el número d'entrada acompanyat d'un missatge de sortida que digui si el número és o no un número estrany.  

int main() {
    int num = 0;
    cin >> num;

    // Per a saber el nombre de dígits que té:
    int digits = 1;
    if (num >= 10) {
        digits += 1;
        if (num >= 100) {
            digits += 1;
            if (num >= 1000) {
                digits += 1;
            }
        }
    }

    // Per a obtenir l'operador:
    int operador = 1;
    for (int i = 1; i < digits; i++) operador *= 10;

    // Per a saber quin número és cada un dels dígits:
    int num2 = num;
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;
    int digit4 = 0;
    for (int i = 1; num2 > 0; i++) {
        num2 -= operador;

        if (num2 < operador) {
            if (operador == 1000) digit4 = i;
            else if (operador == 100) digit3 = i;
            else if (operador == 10) digit2 = i;
            else digit1 = i; // Si entra, vol dir que l'operador = 1.

            operador /= 10;
            i = 0;

            if (num2 < operador) operador /= 10;
        }
    }

    // Per a fer l'operació per tal de veure si és o no un número estrany:
    int digit1_op = digit1;
    for (int i = 1; i < digits; i++) digit1 *= digit1_op; // Per a fer la potència de cada dígit.

    int digit2_op = digit2;
    for (int i = 1; i < digits; i++) digit2 *= digit2_op;

    int digit3_op = digit3;
    for (int i = 1; i < digits; i++) digit3 *= digit3_op;

    int digit4_op = digit4;
    for (int i = 1; i < digits; i++) digit4 *= digit4_op;

    int operacio = digit1 + digit2 + digit3 + digit4;

    // Per saber si el número és o no un número estrany:
    if (operacio == num) cout << "strange number: " << num << endl;
    else cout << "not strange number: " << num << endl;
}