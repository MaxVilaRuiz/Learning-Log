#include <iostream>
using namespace std;

int max4(int a, int b, int c, int d){
    int max = a;
    if ((b >= max) and (b >= c) and (b >= d)) max = b;
    else if ((c >= max) and (c >= b) and (c >= d)) max = c;
    else if ((d >= max) and (d >= b) and (d >= c)) max = d;

    return max;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max4(a, b, c, d);
}