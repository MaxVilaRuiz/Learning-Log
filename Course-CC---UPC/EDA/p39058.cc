#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> mov_x = {-2, -2, -1, 1, 2, 2, -1, 1};
vector<int> mov_y = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<pair<int,int>> targets;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'C') {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else if (grid[i][j] == 'F') 
                    targets.push_back({i, j});
            }
        }

        while (!q.empty()) {
            pair<int,int> u = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                pair<int,int> new_p = {u.first + mov_y[i], u.second + mov_x[i]};

                if (new_p.first < 0 || new_p.second < 0 || new_p.first >= n || new_p.second >= m) continue;
                if (dist[new_p.first][new_p.second] != -1) continue;
                if (grid[new_p.first][new_p.second] == 'a') continue;
                if (grid[new_p.first][new_p.second] == 'C') continue;

                dist[new_p.first][new_p.second] = dist[u.first][u.second] + 1;
                q.push(new_p);
            }
        }

        int acc = 0;
        float total = 0;
        for (int i = 0; i < targets.size(); i++) {
            if (dist[targets[i].first][targets[i].second] != -1) {
                acc++; 
                total += dist[targets[i].first][targets[i].second];
            }
        }

        if (acc) {
            cout << "flors accessibles: " << acc << "\n";
            cout << "distancia mitjana: " << (float)(total / acc) << "\n";
        }
        else cout << "el cavall no pot arribar a cap flor\n";
    }

    return 0;
}