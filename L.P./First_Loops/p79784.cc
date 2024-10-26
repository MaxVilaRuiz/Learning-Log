#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0;
    char caracter;
    while(cin >> caracter) {
        if (caracter == 'e') x++;
        else if (caracter == 'o') x--;
        else if (caracter == 's') y++;
        else if (caracter == 'n') y--;
    }
    cout << '(' << x << ", " << y << ')' << endl;
}