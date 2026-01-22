#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void backtrack(pair<int,int> pos, string& actual, const vector<vector<char>>& grid, 
                vector<string>& comb, vector<vector<bool>>& used) {
    if (pos.first < 0 || pos.second < 0 || pos.first >= grid.size() || pos.second >= grid[0].size()) {
        comb.push_back(actual);
        return;
    }
    if (used[pos.first][pos.second]) return;

    if (grid[pos.first][pos.second] == 'X') return;
    else if (grid[pos.first][pos.second] == 'A') {
        used[pos.first][pos.second] = true;
        actual.push_back('A');
        backtrack({pos.first+1, pos.second}, actual, grid, comb, used);
        actual.pop_back();
        used[pos.first][pos.second] = false;
    }
    else if (grid[pos.first][pos.second] == 'D') {
        used[pos.first][pos.second] = true;
        actual.push_back('D');
        backtrack({pos.first, pos.second+1}, actual, grid, comb, used);
        actual.pop_back();
        used[pos.first][pos.second] = false;
    }
    else {
        used[pos.first][pos.second] = true;
        actual.push_back('A');
        backtrack({pos.first+1, pos.second}, actual, grid, comb, used);
        actual.pop_back();
        used[pos.first][pos.second] = false;

        used[pos.first][pos.second] = true;
        actual.push_back('D');
        backtrack({pos.first, pos.second+1}, actual, grid, comb, used);
        actual.pop_back();
        used[pos.first][pos.second] = false;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
                
        vector<vector<bool>> used(n, vector<bool>(m, false));
        vector<string> comb;
        string actual = "";
        backtrack({0,0}, actual, grid, comb, used);
        sort(comb.begin(), comb.end());

        for (int i = 0; i < comb.size(); i++)
            cout << comb[i] << "\n";
        cout << "----------\n";
    }

    return 0;
}