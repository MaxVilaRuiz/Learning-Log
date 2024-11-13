#include <iostream>
using namespace std;

int eval() {
    char symb;
    cin >> symb;

    if ((symb != '+') and (symb != '-') and (symb != '*'))
        return int(symb - '0');

    int num1 = eval();
    int num2 = eval();
    if (symb == '+') return num1 + num2;
    else if (symb == '-') return num1 - num2;
    return num1 * num2; // else if (symb == '*')
}


int main() {
    cout << eval() << endl;
}