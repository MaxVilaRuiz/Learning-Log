#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char lletra;
    cin >> lletra;

    if (islower(lletra)){
        lletra = toupper(lletra);
    }
    else {
        lletra = tolower(lletra);
    }

    cout << lletra << endl;
}