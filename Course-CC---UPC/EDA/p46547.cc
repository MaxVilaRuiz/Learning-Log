#include <iostream>
#include <vector>
using namespace std;

void backtrack(int pos, int x, int m, int last, int total, int& res, const vector<vector<int>>& points, vector<bool>& used) {
    if (pos == points.size()) { 
        res = max(total, res);
        return;
    }

    for (int i = 1; i < points.size(); i++) {
        if (used[i]) continue;

        int num = (x * 10 + i) % m;
        if (num == 0) continue;

        used[i] = true;
        if (last == -1) backtrack(pos+1, num, m, i, total, res, points, used);
        else backtrack(pos+1, num, m, i, total + points[last][i], res, points, used);
        used[i] = false;
    }
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vector<int>> points(n+1, vector<int>(n+1));
        for (int i = 1; i < n+1; i++) 
            for (int j = 1; j < n+1; j++) cin >> points[i][j];

        int res = 0;
        vector<bool> used(n+1, false);
        backtrack(1, 0, m, -1, 0, res, points, used);

        cout << res << "\n";
    }

    return 0;
}