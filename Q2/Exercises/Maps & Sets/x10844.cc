#include <iostream>
#include <map>
#include <list>
using namespace std;

int main() {
    map<string, int> M;
    pair<string, int> fruits;
    while (cin >> fruits.first >> fruits.second) {
        M[fruits.first] += fruits.second;
    }   

    list< pair<string, int> > res;
    while (0 < M.size()) {
        auto it = M.begin();
        res.push_back(*it);
        M.erase((*it).first);
    }

    for (auto it = res.begin(); it != res.end(); it++) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
}