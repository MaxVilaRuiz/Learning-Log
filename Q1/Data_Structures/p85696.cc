#include <iostream>
using namespace std;

struct Rational {
    int num, den;
};

int mcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Rational rational(int n, int d) {
    Rational r;
    if (n == 0) {
        r.num = 0;
        r.den = 1;
    }
    else {
        int div;
        if (0 < n and 0 < d) {
            div = mcd(n, d);
            r.num = n/div;
            r.den = d/div;
        }
        else { 
            if (0 < n and d < 0) {
                div = mcd(n, -d);
                r.num = -n/div;
                r.den = -d/div;
            }
            else {
                if (n < 0 and 0 < d) {
                    div = mcd(-n, d);
                    r.num = n/div;
                    r.den = d/div;
                }
                else {
                    div = mcd(-n, -d);
                    r.num = -n/div;
                    r.den = -d/div;
                }
            }
        }
    }
    return r;
}

int main() {}