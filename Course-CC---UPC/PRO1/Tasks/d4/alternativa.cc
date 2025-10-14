#include <iostream>
using namespace std;

int main() {
    int n, n1 ,n2, bit;
    int num = 0, suma = 0, bits = 0, comptador = 0;
    int numero = 1, operador = 1;
    bool modificar = false;

    while (cin >> n) {
        suma = 0;
        n /= 10000;

        while (n > 0) {
            n1 = n % 10; n /= 10;
            n2 = n % 10; n /= 10;

            if (n1 == n2) {
                if (n1 == 1) {
                    num *= 10;
                    num += n1;
                }
                else {
                    if (num == 0) {
                        num = 10;
                        modificar = true;
                    }
                    else num *= 10;
                }

                comptador = 0;
                bits++;
            }
            else if (n1 == 1 and n2 == 0) {
                comptador++;

                for (int i = 0; i < bits; i++) operador *= 10;
                if (modificar) {
                    num -= operador;
                    modificar = false;
                }

                bits--;
                while (num > 0) {
                    bit = num % 10;
                    if (bit == 1) {
                        if (bits > 0) {
                            for (int j = 0; j < bits; j++) {
                                numero *= 2;
                            }
                        }
                        else numero = 1;
                    }

                    bits--;
                    suma += numero;
                    numero = 1;
                    num /= 10;
                }
                num = 0;
                bits = 0;
            }

            if (comptador == 2) {
                cout << suma << endl;
                suma = 0;
            }
        }

        for (int i = 0; i < bits; i++) operador *= 10;
        if (modificar) {
            num -= operador;
            modificar = false;
        }

        bits--;
        while (num > 0) {
            bit = num % 10;
            if (bit == 1) {
                if (bits > 0) {
                    for (int j = 0; j < bits; j++) {
                        numero *= 2;
                    }
                }
                else numero = 1;
            }

            bits--;
            suma += numero;
            numero = 1;
            num /= 10;
        }
        num = 0;
        bits = 0;

        cout << suma << endl;
    }
}