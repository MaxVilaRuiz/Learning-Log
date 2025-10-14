#include <iostream>
#include <map>
using namespace std;

struct Alumne {
    string name;
    int mark;
};

int main() {
    pair<string, int> alumne;
    map<string, pair<int, int> > M;
    while (cin >> alumne.first >> alumne.second) {        
        M[alumne.first].first += alumne.second;
        M[alumne.first].second++;
    }

    for (auto it = M.begin(); it != M.end(); it++) {
        cout << (*it).first << ' ' << (*it).second.first / (*it).second.second << endl;
    }
    
    // for (const auto& [name, mark] : M) {
    //     cout << (*it).first << ' ' << (*it).second.first / (*it).second.second << endl;
    // }
}