#include <iostream>
using namespace std;

struct Clock {
    int h;      // hours (0<=h<24)
    int m;      // minutes (0<=m<60)
    int s;      // seconds (0<=s<60)
};

Clock midnight() {
    Clock res;
    res.h = 0;
    res.m = 0;
    res.s = 0;

    return res;
}

void increase(Clock& r) {
    r.s += 1;
    if (r.s > 59) {
        r.s = 0;
        r.m += 1;
        if (r.m > 59) {
            r.m = 0;
            r.h += 1;
            if (r.h > 23) {
                r.h = 0;
            }
        }
    }
}

void print(const Clock& r) {
    if (r.h < 10)
        cout << 0 << r.h << ':';
    else cout << r.h << ':';

    if (r.m < 10) 
        cout << 0 << r.m << ':';
    else cout << r.m << ':';

    if (r.s < 10) 
        cout << 0 << r.s << endl;
    else cout << r.s << endl;
}

int main() {
    Clock clk;
    int n;
    cin >> clk.h >> clk.m >> clk.s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        increase(clk);
    }

    print(clk);
    midnight();
    print(clk);
}