#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int num2 = num;
    int sum = num % 10;
    while (99 < num2) {
        num2 /= 100;
        sum += num2 % 10;
    }

    if (sum % 2 == 1) cout << num << " NO ES TXATXI" << endl;
    else cout << num << " ES TXATXI" << endl;
}