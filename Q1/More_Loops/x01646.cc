#include <iostream>
using namespace std;

int main() {
    int base;
    cin >> base;

    int num;
    while(cin >> num) {
        int num2 = num;
        int sum = 0;
        while(num2 > 0) {
            sum += (num2 % base);
            num2 /= base;
        }
        cout << num << ": " << sum << endl;
    }
}