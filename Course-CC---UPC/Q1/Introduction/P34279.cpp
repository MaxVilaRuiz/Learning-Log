#include <iostream>
#include <string>
using namespace std;

int main() {
    int h, m, s;
    cin >> h >> m >> s;

    s += 1;
    if (s == 60) {
        m += 1;
        s -= 60;

        if (m == 60) {
            h += 1;
            m -= 60;

            if (h == 24) {
                h = 0;
            }
        }
    }

    string s_string = to_string(s);
    string m_string = to_string(m);
    string h_string = to_string(h);

    if (s_string.length() == 1) {
        s_string = '0' + s_string;
    }
    if (m_string.length() == 1) {
        m_string = '0' + m_string;
    }
    if (h_string.length() == 1) {
        h_string = '0' + h_string;
    }

    cout << h_string << ':' << m_string << ':' << s_string << endl;
}