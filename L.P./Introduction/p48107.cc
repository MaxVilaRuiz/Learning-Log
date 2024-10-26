#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    
    if (b < 0) {
        bool lower = true;

        while (lower) {
            cin >> b;

            if (b > 0) {
                lower = false;
            } 
        }
    }

    int d = a / b;
    int r = (int)a % (int)b;

    cout << d << ' ' << r << endl;
}