#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int n, m, x, y, c;
    while (cin >> n >> m) {
        int total = 0;
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < m; i++) {
            cin >> x >> y >> c;
            if (x != y) {
                adj[x].push_back({y, c});
                adj[y].push_back({x, c});
            }
            total += c;
        }

        vector<bool> used(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        int res = 0;

        while(!pq.empty()) {
            pair<int,int> u = pq.top();
            pq.pop();

            if (used[u.second]) continue;
            res += u.first;
            used[u.second] = true;

            for (pair<int,int> e : adj[u.second]) {
                if (!used[e.first]) {
                    pq.push({e.second, e.first});
                }
            }
        }

        cout << total - res << "\n";
    }

    return 0;
}