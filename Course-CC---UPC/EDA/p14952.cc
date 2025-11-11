#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    while (cin >> n) {
        cin >> m;
    }

    vector< vector<int> > preced(n);
    vector<int> indegree(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        preced[x].push_back(y);
        indegree[y]++;
    }

    priority_queue<int, vector<int>, greater<int> > q;
    for (int t = 0; t < n; t++) {
        if (indegree[t] == 0) q.push(t);
    }

    while (!q.empty()) {
        int x = q.top();
        q.pop();
        cout << x << " ";
    }

    cout << endl;
}