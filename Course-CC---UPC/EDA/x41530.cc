#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<vector<int>> Matrix;

int main() {
    int n, m, x, y;
    while (cin >> n >> m) {
        Matrix adj(n);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<bool> visited(n, false); 
        int vertexs = 0;
        int edges = 0;
        bool isForest = true;
        int trees = 0;

        for (int i = 0; i < n && isForest; i++) {
            if (!visited[i]) {
                stack<int> s;
                vertexs = 0;
                edges = 0;
                s.push(i);

                while(!s.empty()) {
                    int top = s.top();
                    s.pop();

                    visited[top] = true;
                    vertexs++;
                    edges += adj[top].size();

                    for (int e : adj[top]) {
                        if (!visited[e]) s.push(e);
                    }
                }

                edges /= 2;
                if (edges != vertexs - 1) isForest = false;
                else trees++; 
            }
        }

        if (isForest) cout << trees << "\n";
        else cout << "no" << "\n"; 
    }

    return 0;
}