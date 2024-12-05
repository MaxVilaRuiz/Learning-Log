#include <iostream>
using namespace std;

struct Time {
    int hour, minute, second;
};

void one_second(const Time& t, Time& t1, Time& t2) {
    t1 = t;
    t2 = t;

    t1.second += 1;
    if (t1.second > 59) {
        t1.second = 0;
        t1.minute += 1;
        if (t1.minute > 59) {
            t1.minute = 0;
            t1.hour += 1;
            if (t1.hour > 23)
                t1.hour = 0;
        }
    }

    t2.second -= 1;
    if (t2.second < 1) {
        t2.second = 59;
        t2.minute -= 1;
        if (t2.minute < 1) {
            t2.minute = 59;
            t2.hour -= 1;
            if (t2.hour < 1) 
                t2.hour = 23;
        }
    }
}

int main() {
    Time clk;
    while(cin >> clk.hour >> clk.minute >> clk.second) {
        Time clk_plus, clk_mines;
        one_second(clk, clk_plus, clk_mines);

        cout << clk_plus.hour << ' ' << clk_plus.minute << ' ' << clk_plus.second << endl;
        cout << clk_mines.hour << ' ' << clk_mines.minute << ' ' << clk_mines.second << endl;
    }
}