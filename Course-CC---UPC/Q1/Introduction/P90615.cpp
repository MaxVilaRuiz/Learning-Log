#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    if ((x >= y) && (x >= z)) {
        cout << x << endl;
    }
    else if ((x <= y) && (y >= z)) {
        cout << y << endl;
    }
    else {
        cout << z << endl;
    }
}   