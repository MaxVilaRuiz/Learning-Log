#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pair<int,int> m = {n / 2, n / 2}; 
        dist[m.first][m.second] = grid[m.first][m.second];
        pq.push({grid[m.first][m.second], {m.first, m.second}});
        int mov_x[4] = {-1, 1, 0, 0};
        int mov_y[4] = {0, 0, -1, 1};
        pair<int,int> res;

        while (!pq.empty()) {
            pair<int,pair<int,int>> v = pq.top();
            pq.pop();

            if (v.second.first == 0 || v.second.first == n-1 || v.second.second == 0 || v.second.second == n-1) {
                res = {v.second.first, v.second.second};
                break;
            }
            if (grid[v.second.first][v.second.second] > dist[v.second.first][v.second.second]) continue;

            for (int i = 0; i < 4; i++) {
                pair<int,int> np = {v.second.first + mov_x[i], v.second.second + mov_y[i]};
                if (!(np.first < 0 || np.first >= n || np.second < 0 || np.second >= n)) {
                    if (dist[np.first][np.second] > (dist[v.second.first][v.second.second] + grid[np.first][np.second])) {
                        dist[np.first][np.second] = dist[v.second.first][v.second.second] + grid[np.first][np.second];
                        pq.push({dist[np.first][np.second], {np.first, np.second}});
                    } 
                }
            }
        }

        cout << dist[res.first][res.second] << "\n";
    }

    return 0;
}