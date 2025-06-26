#include <iostream>
using namespace std;

int main() {
    int r, c, res = 0;
    char coin;
    cin >> r >> c;
    if (c % 2 != 0) {
        for (int i = 0; i < (r * c); i++) {
            cin >> coin;
            if (i % 2 == 0)
                res += (int(coin) - 48);
        }
    }
    else {
        bool first_white = true;
        for (int i = 0; i < (r * c); i++) {
            cin >> coin;
            if (first_white) {
                if ((i % 2) == 0) 
                    res += (int(coin) - 48);
                else if (((i + 1) % c) == 0)
                    first_white = false;
            }
            else {
                if ((i % 2) == 1)
                    res += (int(coin) - 48);
                if (((i + 1) % c) == 0)
                    first_white = true;
            }
        }
    }

    cout << res << endl;
    return 0;
}