#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    if (!(num1 > -1000) && !(num1 < 1000) || !(num1 > -1000) && !(num1 < 1000)) {
        return 1;
    }

    double operation = (double(num1) + double(num2)) / 2;

    cout << operation << endl;
}