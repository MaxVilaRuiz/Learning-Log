#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);

    int n;
    cin >> n;

    string type;
    double length, width, radius, sol;
    double pi = acos(-1.0);
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == "rectangle") {
            cin >> length >> width;
            sol = length * width;
        }
        else if (type == "circle") {
            cin >> radius;
            sol = pi * radius * radius;
        }

        cout << sol << endl;
    } 
}