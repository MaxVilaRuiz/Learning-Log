#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}

int fatten(int x) {
    if (x <= 9) return x;
    else {
        int f = fatten(x / 10);
        return (f * 10) + max(f % 10, x % 10);
    }
}

int main() {
    int num;
    while (cin >> num) cout << fatten(num) << endl;
}