#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int dr[8] = {-2,-2,-1,-1, 1,1, 2,2};
int dc[8] = {-1, 1,-2, 2,-2,2,-1,1};

// BFS
int knight_distance(int n, int m, pair<int,int> src, pair<int,int> dst) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    dist[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty()) {
        auto [r,c] = q.front();
        q.pop();

        if (r == dst.first && c == dst.second)
            return dist[r][c];

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int W, L;
        cin >> W >> L;

        int k;
        cin >> k;
        vector<pair<int,int>> targets(k);
        for (int i = 0; i < k; ++i)
            cin >> targets[i].first >> targets[i].second;

        long long best = 0;
        long long total_moves = 0;
        pair<int,int> cur = {0,0};

        for (int i = 0; i < k; ++i) {
            int d = knight_distance(n, m, cur, targets[i]);
            if (d == -1) break;

            total_moves += d;
            long long score = (long long)(i+1)*W - total_moves*L;
            best = max(best, score);

            cur = targets[i];
        }

        cout << best << "\n";
    }

    return 0;
}