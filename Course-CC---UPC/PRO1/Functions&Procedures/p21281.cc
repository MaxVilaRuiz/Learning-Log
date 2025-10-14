#include <iostream>
using namespace std;

void factor(int n, int& f, int& q) {
    q = 0;
    for (int div = 2; div*div <= n; div++) {
        int times = 0;
        while(n % div == 0) {
            times++;
            n /= div;
        }
        if (times > q) {
            q = times;
            f = div;
        }
    }
    if (q == 0) {
        f = n;
        q = 1;
    } 
}

int main() {
    int n, f, q;
    cin >> n;
    factor(n, f, q);
    cout << f << ' ' << q << endl;
}