#include <iostream>
#include <string>
using namespace std;

int main() {
    char letra1, letra2;
    cin >> letra1 >> letra2;

    if (letra1 == 'A' && letra2 == 'P') cout << 1 << endl;
    else if (letra2 == 'A' && letra1 == 'P') cout << 2 << endl;
    else if (letra1 == 'P' && letra2 == 'V') cout << 1 << endl;
    else if (letra2 == 'P' && letra1 == 'V') cout << 2 << endl;
    else if (letra1 == 'V' && letra2 == 'A') cout << 1 << endl;
    else if (letra2 == 'V' && letra1 == 'A') cout << 2 << endl;
    else cout << '-' << endl;
}