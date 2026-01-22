#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef vector< vector<char> > Matrix_c;
typedef vector< vector<int> > Matrix_i;

int main() {
    int n, m;
    while (cin >> n >> m) {
        Matrix_c grid(n, vector<char>(m, 0));        
        Matrix_i dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'X') dist[i][j] = -2;
                else if (grid[i][j] == 'T') {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int mov_x[4] = {-1, 1, 0, 0};
        int mov_y[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                pair<int, int> p = {u.first + mov_x[i], u.second + mov_y[i]};
                if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= m)
                    continue;
                if (dist[p.first][p.second] != -1) continue;
                q.push({p.first, p.second});
                dist[p.first][p.second] = dist[u.first][u.second] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) cout << ' ';
                cout << dist[i][j];
            }
            cout << "\n";
        }
        cout << "----------\n";
    }

    return 0;
}