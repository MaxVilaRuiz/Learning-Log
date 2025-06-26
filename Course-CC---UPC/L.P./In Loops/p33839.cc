#include <iostream>
using namespace std;

int main() {
    int num;
    while(cin >> num) {
        int num2 = num;
        int sum = 0;
        while(num2 > 0) {
            sum += (num2 % 10);
            num2 /= 10;
        }

        cout << "The sum of the digits of " << num << " is " << sum << '.' << endl;
    }
}