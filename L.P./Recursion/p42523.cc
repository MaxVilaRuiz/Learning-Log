#include <iostream>
using namespace std;

int mcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a == b) return a;

    int res;
    if (a < b) {
        int div = b / a;
        b -= a * div;
        res = mcd(a, b);
    }
    else if (b < a) { // b < a 
        int div = a / b;
        a -= b * div;
        res = mcd(a, b);
    }

    return res;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << mcd(num1, num2) << endl; 

    return 0;
}