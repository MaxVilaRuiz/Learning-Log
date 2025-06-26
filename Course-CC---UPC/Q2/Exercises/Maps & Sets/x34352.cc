#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> M;
    char code;
    string word;
    while (cin >> code >> word) {
        if (code == 'a') M[word]++;
        else cout << M[word] << endl;
    }
}