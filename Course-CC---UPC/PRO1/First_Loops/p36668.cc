#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int comptador = 1;
    int suma = 0;
    while (comptador <= n) {
        suma += comptador * comptador;
        comptador++;
    }
    
    cout << suma << endl;
}