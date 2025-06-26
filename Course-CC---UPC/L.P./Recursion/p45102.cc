#include <iostream>
using namespace std;

int operation() {
    char symb;
    cin >> symb;

    if (symb == '(') {
        int num1 = operation();

        char op;
        cin >> op;

        int num2 = operation();

        char symb2;
        cin >> symb2; // ')'

        if (op == '+') return num1 + num2;
        else if (op == '-') return num1 - num2;
        else return num1 * num2;
    }
    else { // symb == num
        int res = int(symb - '0');
        return res;
    }
}

int main() {
    cout << operation() << endl;
}