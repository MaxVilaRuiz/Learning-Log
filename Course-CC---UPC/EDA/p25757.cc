#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

int main() {
    int n, m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (cin >> n >> m) {
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) cin >> grid[i];

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'X' || visited[i][j]) continue;

                // BFS
                queue<pair<int,int>> q;
                vector<pair<int,int>> cells;
                set<char> letters;

                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    cells.push_back({r, c});

                    if (grid[r][c] != '.') letters.insert(grid[r][c]);

                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            if (!visited[nr][nc] && grid[nr][nc] != 'X') {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }

                char paint = '.';
                if (letters.size() == 1) paint = *letters.begin();

                for (auto &p : cells)
                    grid[p.first][p.second] = paint;
            }
        }

        for (int i = 0; i < n; ++i)
            cout << grid[i] << "\n";
        cout << "\n";
    }

    return 0;
}