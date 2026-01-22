#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int n, m; 
    string x, y;
    while (cin >> n) {
        vector<string> words(n);        
        unordered_map<string, int> idx;
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            idx[words[i]] = i;
        }

        cin >> m;
        vector<vector<int>> adj(n);
        vector<int> in_queue(n, 0);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[idx[x]].push_back(idx[y]);
            in_queue[idx[y]]++;
        }

        priority_queue<string, vector<string>, greater<string>> pq;
        for (int i = 0; i < n; i++) {
            if (in_queue[i] == 0) {
                pq.push(words[i]);
            }
        }

        string res = "";
        int count = 0;
        
        while(!pq.empty()) {
            string u = pq.top();
            pq.pop();

            res += u;
            count++;

            for (int k : adj[idx[u]]) {
                in_queue[k]--;
                if (in_queue[k] == 0) pq.push(words[k]);
            }
        }

        if (count != n) cout << "NO VALID ORDERING\n";
        else cout << res << "\n";
    }

    return 0;
}