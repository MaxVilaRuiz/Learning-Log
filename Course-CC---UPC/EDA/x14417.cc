#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int n, m, p;
    while (cin >> n >> m) {
        vector<vector<string>> grid(n, vector<string>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> grid[i][j];
        }

        cin >> p;
        vector<string> film(p);
        for (int i = 0; i < p; i++) cin >> film[i];
        
        int total = 0;
        bool impossible = false;
        pair<int,int> pos = {0,0};
        vector<int> mov_x = {-1, 1, 0, 0};
        vector<int> mov_y = {0, 0, -1, 1};

        for (int i = 0; i < p; i++) {
            int last_total = total;
            queue<pair<int,int>> q;
            vector<vector<int>> dist(n, vector<int>(m, -1));
            q.push(pos);

            while (!q.empty()) {
                pair<int,int> u = q.front();
                q.pop();

                if (grid[u.first][u.second] == film[i]) {
                    pos = u;
                    total += dist[u.first][u.second] + 2;
                    break;
                }

                for (int j = 0; j < 4; j++) {
                    pair<int,int> new_pos = {u.first + mov_x[j], u.second + mov_y[j]};
                    if (new_pos.first < 0 || new_pos.second < 0 || new_pos.first >= n || new_pos.second >= m) continue;
                    if (grid[new_pos.first][new_pos.second] == "*") continue;
                    if (dist[new_pos.first][new_pos.second] != -1) continue;
                    dist[new_pos.first][new_pos.second] = dist[u.first][u.second] + 1;
                    q.push(new_pos);
                }
            }

            if (last_total == total) {
                impossible = true;
                break;
            }
        }

        if (impossible) cout << "impossible\n";
        else cout << total << "\n";
    }

    return 0;
}