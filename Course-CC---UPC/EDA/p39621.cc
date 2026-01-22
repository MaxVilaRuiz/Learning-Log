#include <iostream>
#include <vector>
using namespace std;

int n, m, N;
vector<long long> coins;
vector<vector<int>> attacks;
vector<bool> blocked;
long long best;

void backtrack(int pos, long long sum) {
    if (pos == N) {
        best = max(best, sum);
        return;
    }

    backtrack(pos + 1, sum);

    if (!blocked[pos]) {
        vector<int> changed;
        for (int v : attacks[pos]) {
            if (!blocked[v]) {
                blocked[v] = true;
                changed.push_back(v);
            }
        }
        blocked[pos] = true;

        backtrack(pos + 1, sum + coins[pos]);

        blocked[pos] = false;
        for (int v : changed) blocked[v] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        N = n * m;
        coins.resize(N);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> coins[i * m + j];

        attacks.assign(N, vector<int>());
        blocked.assign(N, false);

        int dr[8] = {-2,-2,-1,-1, 1,1, 2,2};
        int dc[8] = {-1, 1,-2, 2,-2,2,-1,1};

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int u = r * m + c;
                for (int k = 0; k < 8; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        attacks[u].push_back(nr * m + nc);
                    }
                }
            }
        }

        best = 0;
        backtrack(0, 0);

        cout << best << "\n";
    }

    return 0;
}