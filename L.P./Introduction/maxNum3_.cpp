#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    bool same = true;

    while (same == true) {
        if ((x != y) && (x != z) && (y != z)) {
            if ((x > y) && (x > z)) {
                cout << x << endl;
            }
            else if ((x < y) && (y > z)) {
                cout << y << endl;
            }
            else {
                cout << z << endl;
            }
            same = false;

        } else {
            cin >> x >> y >> z;
        }
    }
}