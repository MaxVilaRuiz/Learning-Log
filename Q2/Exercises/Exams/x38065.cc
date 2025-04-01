#include <iostream>
#include <map>
using namespace std;

int main() {
    string inst = "";
    string name = "";
    int coins = 0;
    map<string, int> M_pers;
    map<int, int> M_coins;
    while (cin >> inst) {
        if (inst == "ADD") {
            cin >> name >> coins;
            M_pers[name] = coins;
            M_coins[coins]++;
        }
        else if (inst == "DELETE") {
            cin >> name;
            auto it = M_pers.find(name);
            M_coins[(*it).second]--;
            M_pers.erase(it);
        }
        else {
            cin >> coins;
            cout << M_coins[coins] << endl;
        }
    }
}