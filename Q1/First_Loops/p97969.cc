#include <iostream>
using namespace std;

int main() {
    char c;
    int compt = 0;
    while (cin >> c and c != '.') {
        if (c == 'a') compt++;
    }
    cout << compt << endl;
}