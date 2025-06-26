#include <iostream>
using namespace std;

bool prime(int n) {
    if (n < 2) return false;
    else {
        for (int div = 2; div*div <= n; div++)
            if (n % div == 0) return false;
        return true;
    }
}

int next_prime(int p) {
    if (p == 2) return 3;
    else {
        p += 2;
        while (not prime(p)) p += 2;
        return p;
    }
}

int main() {
    int n;
    cin >> n;
    while(prime(n)) {
        cout << next_prime(n) << endl;
        cin >> n;
    }
}