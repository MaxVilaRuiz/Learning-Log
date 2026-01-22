#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }   

    pair<int,int> pos;
    cin >> pos.first >> pos.second;
    pos.first--;
    pos.second--;

    pair<int, int> fs = {-1, -1};
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<int> mov_x = {-1, 1, 0, 0};
    vector<int> mov_y = {0, 0, -1, 1};
    queue<pair<int,int>> q;
    q.push(pos);

    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();

        if (grid[u.first][u.second] == 't') {
            if (fs.first < dist[u.first][u.second]) {
                fs.second = fs.first;
                fs.first = dist[u.first][u.second];
            }
            else if (fs.second < dist[u.first][u.second]) fs.second = dist[u.first][u.second];
        }

        for (int i = 0; i < 4; i++) {
            pair<int,int> new_pos = {u.first + mov_x[i], u.second + mov_y[i]};
            if (new_pos.first < 0 || new_pos.second < 0 || new_pos.first >= n || new_pos.second >= m) continue;
            if (grid[new_pos.first][new_pos.second] == 'X') continue;
            if (dist[new_pos.first][new_pos.second] != -1) continue;
            dist[new_pos.first][new_pos.second] = dist[u.first][u.second] + 1;
            q.push(new_pos);
        }
    }

    if (fs.second == -1) cout << "no es pot arribar a dos o mes tresors\n";
    else cout << "segona distancia maxima: " << fs.second+1 << "\n";

    return 0;
}