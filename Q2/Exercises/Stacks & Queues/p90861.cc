#include <iostream>
#include <vector>
#include <queue>
using namespace std;


queue<string> get_queue(string text, string sep) {
    queue<string> res;

    int start = 0;
    int pos = text.find(sep, start);
    while (pos < text.length() && pos != -1) {
        string piece = text.substr(start, pos - start);
        res.push(piece);

        start = pos + 1;
        pos = text.find(sep, start);
    }

    if (start < text.length()) {
        res.push(text.substr(start));
    }

    return res;
}


int main() {
    int n = 0;
    cin >> n;
    string enter = "";
    getline(cin, enter);

    vector< queue<string> > v (n);
    string clients = "";
    for (int i = 0; i < n; i++) {
        getline(cin, clients);
        if (clients.length() != 0) {
            v[i] = get_queue(clients, " ");
        }
    }

    // vector< queue<string> > v (n);
    // string name = "";
    // char space = ' ';
    // for (int i = 0; i < n; i++) {
    //     int count = 0;
    //     while (cin >> space && space != '\n') {
    //         cin >> name;
    //         if (count == 0) name = space + name;
    //         v[i].push(name);
    //     }
    // }

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    string inst = "";
    while (cin >> inst) {
        int cua = 0;
        string name = "";

        if (inst == "ENTRA") {
            cin >> name >> cua;
            if (0 <= cua && cua <= n) {
                v[cua - 1].push(name);
            }
        }
        else if (inst == "SURT") {
            cin >> cua;
            if (0 <= cua && cua <= n) {
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
            cout << ' ' << v[i].front() << ' ';
            v[i].pop();
        }
        cout << endl;
    }
}