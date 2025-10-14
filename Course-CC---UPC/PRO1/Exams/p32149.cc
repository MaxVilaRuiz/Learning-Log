#include <iostream>
using namespace std;

bool es_ascendent(int n) {
    int actual = n % 10;
    n /= 10;
    int previous = n % 10;

    while (n > 0) {
        if ((previous != (actual - 1)) and (actual != 0)) return false;
        else if ((actual == 0) and (previous != 9)) return false;
        n /= 10;
        actual = previous;
        previous = n % 10;
    }

    return true;
}

int main() {
    int num;
    bool primer = false, segon = false;
    while (cin >> num) {
        if (es_ascendent(num)) {
            if (primer) segon = true;
            else primer = true;
        }
        else primer = false;
    }

    if (segon) cout << "SI" << endl;
    else cout << "NO" << endl;
}