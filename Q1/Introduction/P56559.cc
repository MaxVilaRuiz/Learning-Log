#include <iostream>
using namespace std;

int main() {
    int a1, b1;
    cin >> a1 >> b1;

    int a2, b2;
    cin >> a2 >> b2;

    int sol_int = 0;
    char sol_char = 'n';
    if ((a1 == a2) && (b1 == b2)) {
        sol_char = '=';
    }
    else if ((a1 >= a2) && (b1 < b2) || (a1 > a2) && (b1 <= b2)) {
        sol_int = 1;
    }
    else if ((a1 <= a2) && (b1 > b2) || (a1 < a2) && (b1 >= b2)) {
        sol_int = 2;
    }
    else {
        sol_char = '?';
    }

    if (sol_int == 0) {
        cout << sol_char << endl;
    }
    else {
        cout << sol_int << endl;
    }
}