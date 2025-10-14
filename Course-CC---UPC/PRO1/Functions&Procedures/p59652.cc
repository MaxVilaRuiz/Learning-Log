#include <iostream>
using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void read_rational(int& num, int& den){
    char c;
    cin >> num >> c >> den;
    int d = mcd(num, den);
    num = num / d;
    den = den / d;
}

int main() {
    int n, d;
    read_rational(n, d);
    cout << n << ' ' << d << endl;
}