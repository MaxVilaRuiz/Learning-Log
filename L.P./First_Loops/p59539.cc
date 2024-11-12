#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    cin >> n;

    double harmonic_number = 0;
    for (int i = 1; i <= n; ++i) {
        harmonic_number += 1.0 / i;
    }

    cout << harmonic_number << endl;
}