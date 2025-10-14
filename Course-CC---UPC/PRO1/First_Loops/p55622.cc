#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int digits = 1;
    int num2 = num;
    while(num2 > 9) {
        digits++;
        num2 /= 10;
    }

    cout << "The number of digits of " << num << " is " << digits << '.' << endl;
}