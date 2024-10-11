#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    char c;
    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < b.length(); i++) {
        b[i] = tolower(b[i]);
    }

    if (a > b) {
        cout << a << " > " << b << endl;
    }  
    else if (a < b) {
        cout << a << " < " << b << endl;
    }
    else { // Both have the same length
        cout << a << " = " << b << endl;
    } 
}