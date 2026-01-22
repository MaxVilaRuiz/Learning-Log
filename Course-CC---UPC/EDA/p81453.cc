#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end());
        }

        vector<int> dist(n, -1), parent(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        // BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<int> path;
        for (int v = n - 1; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < (int)path.size(); ++i) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
    }

    return 0;
}