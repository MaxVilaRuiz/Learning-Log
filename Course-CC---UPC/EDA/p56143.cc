#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> mov_x = {-1, -1, 1, 1, -1, 1, 0, 0};
vector<int> mov_y = {-1, 1, 1, -1, 0, 0, -1, 1};

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
        pair<int,int> start, target;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'K') {
                    start = {i, j};
                    q.push(start);
                    dist[i][j] = 1;
                }
            }
        }

        int res = -1;
        while(!q.empty()) {
            pair<int,int> u = q.front();
            q.pop();

            if (grid[u.first][u.second] == 'F') {
                res = dist[u.first][u.second];
                target = u;
                break;
            }

            for (int i = 0; i < 8; i++) {
                pair<int,int> new_p = {u.first + mov_y[i], u.second + mov_x[i]};

                if (new_p.first < 0 || new_p.second < 0 || new_p.first >= n || new_p.second >= m) continue;
                if (dist[new_p.first][new_p.second] != -1) continue;
                if (grid[new_p.first][new_p.second] == 'X') continue;
                if (grid[new_p.first][new_p.second] == 'K') continue;

                dist[new_p.first][new_p.second] = dist[u.first][u.second] + 1;
                parent[new_p.first][new_p.second] = u;
                q.push(new_p);
            }
        }

        if (res == -1) cout << 0 << "\n";
        else {
            cout << res;

            vector<pair<int,int>> path;
            while (target != start) {
                path.push_back(target);
                target = parent[target.first][target.second];
            }
            path.push_back(start);

            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << "  " << path[i].first << ' ' << path[i].second;
            }
            cout << "\n";
        }
    }

    return 0;
}