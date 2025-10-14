#include <iostream>
using namespace std;

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    if (((a1 >= a2) && (b1 <= b2)) && ((a1 != a2) || (b1 != b2))) {
        cout << 1 << " , ";
    }
    else if (((a2 >= a1) && (b2 <= b1)) && ((a1 != a2) || (b1 != b2))) {
        cout << 2 << " , ";
    }
    else if ((a1 == a2) && (b1 == b2)) {
        cout << '=' << " , ";
    }
    else {
        cout << '?' << " , ";
    }

    int a3, b3;
    if ((a1 >= a2) && (a1 <= b2))  {
        a3 = a1;
        b3 = b2;

        if (b1 < b2) b3 = b1;

        cout << '[' << a3 << ',' << b3 << ']' << endl;
    }
    else if (b1 >= a2 && (a1 <= b2)) {
        a3 = a2;
        b3 = b1;
        
        if (b1 > b2) b3 = b2;

        cout << '[' << a3 << ',' << b3 << ']' << endl;
    }
    else cout << "[]" << endl;
}