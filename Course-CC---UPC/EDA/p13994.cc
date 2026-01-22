#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m, v, u, d, x, y;
    while (cin >> n >> m) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++) {
            cin >> v >> u >> d;
            adj[v].push_back({u, d});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);

        cin >> x >> y;
        dist[x] = 0;
        pq.push({0, x});

        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            if (p.first > dist[p.second]) continue;
            if (p.second == y) break;

            for (pair<int,int> e : adj[p.second]) {
                if (dist[e.first] > dist[p.second] + e.second) {
                    dist[e.first] = dist[p.second] + e.second;
                    pq.push({dist[e.first], e.first});
                    parent[e.first] = p.second;
                }
            }
        }

        if (dist[y] == INT_MAX) {
            cout << "no path from " << x << " to " << y << "\n";
            continue;
        }
        
        vector<int> path;
        for (int i = y; i != -1; i = parent[i]) path.push_back(i);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
    }

    return 0;
}