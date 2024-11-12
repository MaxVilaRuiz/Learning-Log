#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int r;
    while(num >= 16) {
        r = num % 16;
        if (r < 10) cout << r;
        else if (r == 10) cout << 'A';
        else if (r == 11) cout << 'B';
        else if (r == 12) cout << 'C';
        else if (r == 13) cout << 'D';
        else if (r == 14) cout << 'E';
        else if (r == 15) cout << 'F';

        num /= 16;
    } 

    r = num % 16;
    if (r < 10) cout << r;
    else if (r == 10) cout << 'A';
    else if (r == 11) cout << 'B';
    else if (r == 12) cout << 'C';
    else if (r == 13) cout << 'D';
    else if (r == 14) cout << 'E';
    else if (r == 15) cout << 'F';
    cout << endl;
}