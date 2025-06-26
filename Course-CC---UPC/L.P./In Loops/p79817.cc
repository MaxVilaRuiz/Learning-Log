#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b) {
        int pow = 1;
        if (b == 0) cout << 1 << endl;
        else if (a == 0) cout << 0 << endl;
        else {
            for(int i = 0; i < b; i++) {
                pow *= a;
            }
            cout << pow << endl;
        }
    }
}