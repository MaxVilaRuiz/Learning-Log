#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> chars = {'A','C','G','T'};
vector<string> res;

void backtrack(int n, string& s) {
    if (s.size() == n) {
        res.push_back(s);
        return;
    }

    for (int i = 0; i < 4; i++) {
        s.push_back(chars[i]);
        backtrack(n, s);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    string s = "";
    backtrack(n, s);

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}