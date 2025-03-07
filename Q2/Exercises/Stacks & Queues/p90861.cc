#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int n = 0;
    cin >> n;
    char c = cin.get();

    vector< queue<string> > v (n);
    int count = 0;
    string name = "";
    while (count < n) {
        c = cin.get();
        if (c == char(10)) {
            if (name.length() > 0) v[count].push(name);
            name = "";
            count++;
        }
        else if (c == ' ') {
            if (name.length() > 0) v[count].push(name);
            name = "";
        }
        else name += c;
    }

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    string inst = "";
    while (cin >> inst) {
        int cua = 0;
        string name = "";

        if (inst == "ENTRA") {
            cin >> name >> cua;
            if (0 < cua && cua <= n) {
                v[cua - 1].push(name);
            }
        }
        else if (inst == "SURT") {
            cin >> cua;
            if (0 < cua && cua <= n) {
                if (!v[cua - 1].empty()) {
                    cout << v[cua - 1].front() << endl;
                    v[cua - 1].pop();
                }
            }
        }
    }

    cout << endl;
    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "cua " << i + 1 << ':';
        while (!v[i].empty()) {
            cout << ' ' << v[i].front();
            v[i].pop();
        }
        cout << endl;
    }
}