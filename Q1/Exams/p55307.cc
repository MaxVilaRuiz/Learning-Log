#include <iostream>
using namespace std;

int suma_divisors(int a) {
    int suma = 1, divisor = 2;
    while (divisor <= (a / 2)) {
        if (a % divisor == 0) suma += divisor;
        divisor++;
    }

    return suma;
}

bool son_amics(int a, int b) {
    if ((suma_divisors(a) == b) and (suma_divisors(b) == a)) return true;
    else return false;
}

int main() {
    int n1, n2;
    bool primer = true;
    while (cin >> n1 >> n2) {
        if (son_amics(n1, n2) and (n1 != n2)) {
            if (primer) {
                cout << '(' << n1 << ' ' << n2 << ')';
                primer = false;
            }
            else cout << ',' << '(' << n1 << ' ' << n2 << ')';
        }
    }
    cout << endl;
}