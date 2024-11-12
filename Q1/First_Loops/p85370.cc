#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    double c, i;
    int t;
    string type;
    cin >> c >> i >> t >> type;

    if (type == "simple") {
        c *= (1 + (i / 100) * t);
    }
    else if (type == "compound") {
        for(int j = 0; j < t; j++) {
            c *= (1 + (i / 100));
        }
    }

    cout << c << endl;
}