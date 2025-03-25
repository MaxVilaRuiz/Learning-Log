#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Log {
    string ip;
    string path;
    int time;
};

struct Map_content {
    int count;
    vector<string> paths;
};

// Pre:
// Post:
void insert_v(vector<string>& v, string s) {
    v.push_back(s);
    int i = v.size() - 1;
    while (0 < i && s < v[i-1]) {
        v[i] = v[i-1];
        i--;
    }
    v[i] = s;
}

int main() { 
    map<string, Map_content > M;   
    Log access1, access2;
    cin >> access1.ip >> access1.path >> access1.time;

    while (cin >> access2.ip >> access2.path >> access2.time) {
        if (access1.time - access2.time < 100) {
            insert_v(M[access1.ip].paths, access1.path);
            if (access1.ip == access2.ip) M[access1.ip].count++;
            else {
                if (M[access1.ip].count < 20) M[access1.ip].count = 0;
            }
        }
        access1 = access2;
    }

    int i = 0;
    for (auto it = M.begin(); it != M.end(); it++) {
        if (20 <= (*it).second.count) {
            cout << (*it).first << ' ';
            for (int i = 0; i < (*it).second.paths.size(); i++) {
                cout << (*it).second.paths[i] << ' ';
            }
            cout << endl;
            i++;
        }
    }
    if (i == 0) cout << "No bots" << endl;
}