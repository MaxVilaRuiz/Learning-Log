#include <iostream>
using namespace std;

int power(int n, int k, int m) {
    if (k == 0) return 1;
    else if (k == 1) return n % m;
    else if (k % 2 == 0) {
        int tmp = power(n, k / 2, m);
        return (tmp * tmp) % m;
    } 
    else { // k senar
        int tmp = power(n, k / 2, m);
        return ((tmp * tmp) % m) * (n % m) % m;
    }
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        cout << power(n, k, m) << endl;
    }
}