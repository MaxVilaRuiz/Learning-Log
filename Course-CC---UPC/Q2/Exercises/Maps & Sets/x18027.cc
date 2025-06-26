#include <iostream>
#include <map>
#include <list>
using namespace std;

list< pair<string, int> > all_pairs(map<string, int>& M) {
    list< pair<string, int> > res;
    while (0 < M.size()) {
        auto it = M.begin();
        pair<string, int> menor = *it;

        for (auto it2 = it++; it2 != M.end(); it2++) {
            if ((*it2).first < menor.first) {
                menor = *it2;
            }
        }

        res.push_back(menor);
        M.erase(menor.first);
    }

    return res;
}