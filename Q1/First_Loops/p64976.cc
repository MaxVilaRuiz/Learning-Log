#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int multiplicador = 1;
    while (multiplicador <= n) {
        cout << n << " x " << multiplicador << " = " << n * multiplicador << endl;
        multiplicador++;
    }
}