#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int n;
    cin >> n;

    float comptador = 1;
    float suma = 0;
    while (comptador <= n) {
        suma += 1/comptador;
        comptador++;
    }
    cout << suma << endl;
}