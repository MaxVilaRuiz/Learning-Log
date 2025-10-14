#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Visita {
    string tourist;
    int year;
    string city;
};

int main() {
    map< int, map<string, vector<string> > > M;
    Visita v;
    while (cin >> v.tourist >> v.year >> v.city) {
        auto it = M.find(v.year);
        auto it2 = (*it).second.find(v.city);
        (*it2).second.push_back(v.tourist); 
    }

    for (auto it = M.begin(); it != M.end(); it++) {
        for (auto it2 = (*it).second.begin(); it2 != (*it).second.end(); it2++) {
            if (1 < (*it2).second.size()) {
                cout << (*it).first << ' ' << (*it2).first << ':';
                sort((*it2).second.begin(), (*it2).second.end());
                for (int i = 0; i < (*it2).second.size(); i++) {
                    cout << ' ' << (*it2).second[i];
                }
                cout << endl;
            }
        }
    }
}