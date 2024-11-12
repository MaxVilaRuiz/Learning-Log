#include <iostream>
using namespace std;

int digits_baseX(int num, int base) {
    int compt = 1;
    while(num >= base) {
        num /= base;
        compt++;
    }

    return compt;
}

int main() {
    int num;
    cin >> num;

    for (int i = 2; i <= 16; i++) {
        cout << "Base " << i << ": " << digits_baseX(num, i) << " cifras." << endl;
    }
}