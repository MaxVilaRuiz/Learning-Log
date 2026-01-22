#include <iostream>
#include <vector>
#include <string>
using namespace std;

int backtrack(int pos, int x, const vector<int>& coins, int total) {
    if (total == x) return 1;
    if (total > x) return 0;
    if (pos == coins.size()) return 0;

    int res = 0;
    res += backtrack(pos+1, x, coins, total);

    if (total + coins[pos] <= x) 
        res += backtrack(pos+1, x, coins, total + coins[pos]);
    
    if (total + 2*coins[pos] <= x) {
        res += backtrack(pos+1, x, coins, total + 2*coins[pos]);
    }

    return res;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        vector<int> coins(n);
        for (int i = 0; i < n; i++) cin >> coins[i];
    
        cout << backtrack(0, x, coins, 0) << "\n";
    }

    return 0;
}