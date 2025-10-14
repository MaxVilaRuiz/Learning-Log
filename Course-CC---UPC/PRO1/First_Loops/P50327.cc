#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    while (9 < num) {
        cout << num % 10;
        num /= 10;
    }

    cout << num << endl;
}