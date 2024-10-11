#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int multiplicador = 1;
    while (multiplicador <= 10) {
        cout << n << '*' << multiplicador << " = " << n * multiplicador << endl;
        multiplicador++;
    }
}