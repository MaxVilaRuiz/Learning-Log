#include <iostream>
using namespace std;

int main() {
    char lletra;
    int comptador = 0;
    bool final = false;
    while ((cin >> lletra) and (not final)) {
        if (lletra == 'a') comptador++;
        final = lletra == '.';
    }
    cout << comptador << endl;
}