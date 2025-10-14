#include <iostream>
using namespace std;

pair<int, int> divmod(int a, int b) {
    return {a / b, a % b};
}

int main() {
    int a, b;
    cin >> a >> b;
    pair<int, int> res = divmod(a, b);
    cout << res.first << ' ' << res.second << endl;
}