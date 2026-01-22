#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef vector< vector<char> > Matrix_char;
typedef vector< vector<bool> > Matrix_bool;

int main() {
    int n, m;
    cin >> n >> m;

    Matrix_char grid(n, vector<char>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int f, c;
    cin >> f >> c;

    // Convert indexes to 0-based
    f--; 
    c--;

    Matrix_bool visited(n, vector<bool>(m, false));
    queue< pair<int, int> > q;

    q.push({f, c});
    visited[f][c] = true;

    int treasures = 0;

    // Movements
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (grid[p.first][p.second] == 't') treasures++;

        for (int i = 0; i < 4; ++i) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (!visited[nr][nc] && grid[nr][nc] != 'X') {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << treasures << "\n";
    return 0;
}