#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
vector<char> especies;
unordered_map<char, int> idxs;
vector<vector<bool>> inc;
vector<char> res;
vector<bool> used;

void backtrack(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) cout << res[i];
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (pos > 0 && inc[i][idxs[res[pos-1]]]) continue; 

        used[i] = true;
        res.push_back(especies[i]);
        backtrack(pos+1);
        res.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> n;

    especies.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> especies[i];
        idxs[especies[i]] = i;
    }

    int m;
    cin >> m;

    inc.assign(n, vector<bool>(n, false));
    char c1, c2;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        inc[idxs[c1]][idxs[c2]] = true;
        inc[idxs[c2]][idxs[c1]] = true;
    }
    
    used.assign(n, false);
    backtrack(0);

    return 0;
}