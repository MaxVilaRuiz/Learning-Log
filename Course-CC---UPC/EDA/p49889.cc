#include <iostream>
#include <vector>
using namespace std;

void backtracking(int i, int n, vector<char>& res, const vector<char>& cons, const vector<char>& vocal, 
                  vector<bool>& cons_b, vector<bool>& vocal_b) {
    if (i == 2 * n) {
        for (int j = 0; j < 2*n; j++) cout << res[j];
        cout << "\n";
        return;
    }

    if (i % 2 == 0) {
        for (int j = 0; j < n; j++) {
            if (!cons_b[j]) {
                cons_b[j] = true;
                res.push_back(cons[j]);
                backtracking(i+1, n, res, cons, vocal, cons_b, vocal_b);
                res.pop_back();
                cons_b[j] = false;
            }
        }
    }
    else {
        for (int j = 0; j < n; j++) {
            if (!vocal_b[j]) {
                vocal_b[j] = true;
                res.push_back(vocal[j]);
                backtracking(i+1, n, res, cons, vocal, cons_b, vocal_b);
                res.pop_back();
                vocal_b[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> cons(n), vocal(n);
    for (int i = 0; i < n; i++) cin >> cons[i];
    for (int i = 0; i < n; i++) cin >> vocal[i];

    vector<char> res;
    vector<bool> cons_b(n, false), vocal_b(n, false);
    backtracking(0, n, res, cons, vocal, cons_b, vocal_b);

    return 0;
}