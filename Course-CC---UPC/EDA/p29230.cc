#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50};

void backtrack(int idx, int n, vector<int>& comb, vector<vector<int>>& res) {
    if (n < 0) return;
    if (n == 0) {
        vector<int> v = comb; 
        sort(v.begin(), v.end(), greater<int>());
        res.push_back(v);
        return;
    }   

    for (int i = idx; i < 6; i++) {
        comb.push_back(coins[i]);
        backtrack(i, n-coins[i], comb, res);
        comb.pop_back();
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> comb;
        vector<int> combA;
        backtrack(0, n, combA, comb);
        
        sort(comb.begin(), comb.end(), greater<vector<int>>());
        for (int i = 0; i < comb.size(); i++) {
            for (int j = 0; j < comb[i].size(); j++) {
                if (j) cout << " ";
                cout << comb[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}