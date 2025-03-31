#include <iostream>
#include <map>
using namespace std;

struct Visita {
    string tourist;
    int year;
    string city;
};

int main() {
    map< string, vector< pair<int, string> > > M;
    Visita v;
    while (cin >> v.tourist >> v.year >> v.city) {
        auto it = M.find(v.city);
        if (it != M.end()) {
            for (int i = 0; i < (*it).second.size(); i++) {
                
            }
        }
    }
}