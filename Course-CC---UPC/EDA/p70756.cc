#include <iostream>
#include <vector>
using namespace std;

void print_sets(int p, const vector<vector<string>>& subsets) {
    for (int i = 0; i < p; i++) {
        cout << "subconjunt " << i+1 << ": {";
        for (int j = 0; j < subsets[i].size(); j++) {
            if (j) cout << ',';
            cout << subsets[i][j];
        }
        cout << "}\n";
    }
    cout << "\n";
}

void backtracking(int i, int n, int p, const vector<string>& words, vector<vector<string>>& subsets) {
    if (i == n) {
        print_sets(p, subsets);
        return;
    }

    for (int j = 0; j < p; j++) {
        subsets[j].push_back(words[i]);
        backtracking(i+1, n, p, words, subsets);
        subsets[j].pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    int p;
    cin >> p;
    vector<vector<string>> subsets(p, vector<string>());

    backtracking(0, n, p, words, subsets);

    return 0;
}