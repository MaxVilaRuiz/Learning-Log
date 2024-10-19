#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n_sequencies;
    cin >> n_sequencies;

    double minim, maxim, mitjana;
    double n = 0;
    int n_numeros, comptador;
    for (int i = 0; i < n_sequencies; i++) {
        cin >> n_numeros >> n;
        minim = maxim = n;
        mitjana = n;
        comptador = 1;

        while ((comptador < n_numeros) and (cin >> n)) {
            if (n < minim) minim = n;
            else if (n > maxim) maxim = n;
            mitjana += n;

            comptador++;
        }

        cout << minim << ' ' << maxim << ' ' << mitjana / n_numeros << endl;
    }
}