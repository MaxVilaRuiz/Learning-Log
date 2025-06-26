#include <iostream>
using namespace std;

int main() {
    int r, c, res = 0;
    char coin;
    cin >> r >> c;
    for (int i = 0; i < (r * c); i++) {
        cin >> coin;
        res += (int(coin) - 48);
    }

    cout << res << endl;
    return 0;
}