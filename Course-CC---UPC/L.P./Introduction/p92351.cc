#include <iostream>
using namespace std;

int main() {
    int a;
    double b;
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

    if (r < 0) {
        r += b;
        d -= 1;
    }

    cout << d << ' ' << r << endl;
}