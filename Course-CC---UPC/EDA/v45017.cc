#include <iostream>
#include <vector>
using namespace std;

void backtrack(int pos, int& total, int actualL, int actualR, const vector<int>& v, 
                vector<bool>& used) {
    if (actualR > actualL) return;
    if (pos == v.size()) {
        total++;
        return;
    }

    for (int i = 0; i < v.size(); i++) {    
        if (used[i]) continue;

        used[i] = true;

        // Left plate
        backtrack(pos+1, total, actualL + v[i], actualR, v, used);

        // Rigth plate 
        backtrack(pos+1, total, actualL, actualR + v[i], v, used);

        used[i] = false;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> weights(n);
        for (int i = 0; i < n; i++) cin >> weights[i];

        int total = 0, actualL = 0, actualR = 0;
        vector<bool> used(n);
        backtrack(0, total, actualL, actualR, weights, used);

        cout << total << "\n";
    }

    return 0;
}