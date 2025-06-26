#include <iostream>
using namespace std;

char encoded(char c, int k) {
    int pos = k + c - 'a';
    if (25 < pos) pos %= 26;
    return 'A' + pos;
    // Passa a 'char' directament perquè és el 
    // tipus de valor que retorna la funció.
}

int main() {
    int k;
    while(cin >> k) {
        char c;
        while(cin >> c and c != '.') {
            if (int(c) > 96 and int(c) < 123) {
                cout << encoded(c, k);
            }
            else if (c == '_') cout << ' ';
            else cout << c;
        }
        cout << endl;
    }
}