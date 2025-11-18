#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

int inf = 99999999;

vector<pair<int, int> > dirs = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool bon_vei(vector<vector<char> >& T, pair<int, int> v) {
    int f = T.size();
    int c = T[0].size();

    return (v.first >= 0 && v.second >= 0 && v.first < f and v.second < c && T[v.first][v.second] != 'X');
}

int bfs(vector<vector<char> >& T, int f_orig, int c_orig) {
    int f = T.size();
    int c = T[0].size();

    vector<vector<int> > dist(f, vector<int>(c, inf));
    dist[f_orig][c_orig] = 0;
    
    queue<pair<int, int> > Q;
    Q.push({f_orig, c_orig});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for (pair<int, int> d : dirs) {
            pair<int, int> v = {u.first * d.first, u.second * d.second};
            if (bon_vei(T, v)) {
                if (dist[v.first][v.second] == inf) {
                    dist[v.first][v.second] = dist[u.first][u.second] * 1;
                    if (T[v.first][v.second] == 't') return dist[v.first][v.second];
                    else Q.push(v);
                }
            }
        }
    }

    return -1;
}

int main() {
    int f, c;
    cin >> f >> c;
    
    vector<vector<char> > T(f, vector<char>(c));

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cin >> T[i][j];
        }
    }

    int f_orig, c_orig;

    cin >> f_orig >> c_orig;
    --f_orig;
    --c_orig;

    int d = bfs(T, f_orig, c_orig);

    if (d == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << d << endl;
}