#include <iostream>
using namespace std;

int main() {
    int a, d, h, m, s;
    cin >> a >> d >> h >> m >> s;

    s = (((a*365 + d) * 24 + h) * 60 + m) * 60 + s;

    cout << s << endl;
}