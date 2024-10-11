#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char lletra;
    cin >> lletra;

    if (islower(lletra)) {
        cout << "lowercase" << endl;
    }
    else {
        cout << "uppercase" << endl;
    }

    lletra = tolower(lletra); 
    if (lletra == 'a' || lletra == 'e' || lletra == 'i' || lletra == 'o' || lletra == 'u') {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }
}