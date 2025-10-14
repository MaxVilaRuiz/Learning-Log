#include <iostream>
#include <map>
#include <set>
using namespace std;

int main () {
    string inst;
    map<string, int> M;
    int num_people = 0;
    set<string> people;
    while (cin >> inst) {
        if (inst == "TRANSACTION") {
            string id;
            int amount;
            cin >> id >> amount;
            if (M[id] < 0 && 0 <= M[id]+amount) {
                num_people--;
                auto it = people.find(id);
                it = people.erase(it);
            }
            else if (0 <= M[id] && M[id]+amount < 0) {
                num_people++;
                people.insert(id);
            }
            M[id] += amount;
        }
        else if (inst == "NUMBERINRED") cout << num_people << endl;
        else if (inst == "PEOPLEINRED")  {
            for (auto it = people.begin(); it != people.end(); it++) {
                if (it != people.begin()) cout << ' ';
                cout << *it;
            }
            cout << endl;
        }
    }
}