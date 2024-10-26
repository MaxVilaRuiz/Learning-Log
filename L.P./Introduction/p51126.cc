#include <iostream>
using namespace std;

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

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