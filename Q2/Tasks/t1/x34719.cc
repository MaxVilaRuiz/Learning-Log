#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Log {
    string ip;
    string path;
    int time;
};

struct Map_content {
    int count;
    int last;
    vector<string> paths;
};

// Pre: Llistat d'accessos web formats per una IP, un path i un temps 
//      (string, string i int, respectivament).
// Post: Es mostra "No bots" si no s'ha detectat cap bot. Altrament, per cada bot detectat 
//       mostra un línia amb la IP i tots els paths d'aquell bot ordenats lexicogràficament.
int main() { 
    map<string, Map_content > M;   
    vector<string> bots;
    Log access;
    while (cin >> access.ip >> access.path >> access.time) {
        auto it = M.find(access.ip);

        if (it != M.end()) {
            if (access.time - (*it).second.last < 100) {
                (*it).second.count++;
                if ((*it).second.count == 20) bots.push_back(access.ip);
            }
            else {
                if ((*it).second.count < 20) (*it).second.count = 1;
            }

            auto i = find((*it).second.paths.begin(), (*it).second.paths.end(), access.path);
            if (i == (*it).second.paths.end()) {
                (*it).second.paths.push_back(access.path);
            }

            (*it).second.last = access.time;
        }
        else {
            M[access.ip] = {1, access.time, {access.path}};
        }
    }

    // Output
    if (0 < bots.size()) {
        sort(bots.begin(), bots.end());
        for (int i = 0; i < bots.size(); i++) {
            cout << bots[i];
            sort(M[bots[i]].paths.begin(), M[bots[i]].paths.end());
            for (int j = 0; j < M[bots[i]].paths.size(); j++) {
                cout << ' ' << M[bots[i]].paths[j];
            }
            cout << endl;
        }
    }
    else cout << "No bots" << endl;
}