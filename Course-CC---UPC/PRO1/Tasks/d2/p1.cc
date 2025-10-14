#include <iostream>
using namespace std;

// PRE: L'entrada ha de ser un nombre positiu (n > 0)
//      preguntant pels primers 'n' nombres estranys.
// POST: S'ha de mostrar un llista dels primers 'n' nombres estranys. 
//       Els números de sortida han de ser majors a 0 (num > 0) i han 
//       de ser números estranys, és a dir, que si en sumar cadascuna 
//       de les seves xifres elevades al nombre de xifres que el formen, 
//       obtenim el propi número.

int main() {
    int n;
    cin >> n;

    int contador = 0;
    int num = 1;
    int num2 = 0;
    int operador = 10;
    int digits = 1;
    int operacio = 1;
    int suma = 0;

    // Inv: contador <= n
    while (contador < n) {
        // Si el nombre està entre l'interval [1,9], és un nombre estrany.
        if (num >= 1 and num <= 9) {
            cout << num << ' ';
            contador += 1;
        }
        else {
            // Inv: operador < (num + 10)
            while (operador <= num) { // Per saber el nombre de dígits que té 'num'.
                digits += 1;
                operador *= 10;
            }

            num2 = num;
            suma = 0;
            // Sumatori de cadascuna de les xifres de 'num' elevades a 'digits'.
            for (int i = 0; i < digits; i++) {
                // Càlcul de cada xifra elevada a 'digits'.
                for (int j = 0; j < digits; j++) operacio *= (num2 % 10);
                suma += operacio;
                operacio = 1;
                num2 /= 10;
            }
            
            if (suma == num) { // Per a saber si és o no un número estrany.
                cout << num << ' ';
                contador += 1;
            }
        }
        num += 1;
    } 
}