#include <iostream>
#include <vector>
#include <map>
using namespace std;

int my_lower_bound(const vector<int>& v, int target) {
    int l = 0, r = v.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] < target) l = mid + 1;
        else r = mid;
    }
    if (v[l] == target) return l;
    return -1;
}

int main() {
    int n, s, m, a, res, count = 1;
    while (cin >> n) {
        vector<int> targets(n);
        for (int i = 0; i < n; i++) {
            cin >> s;
            targets[i] = s - (i + 1);
        }

        cout << "Sequence #" << count << "\n";
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a;
            res = my_lower_bound(targets, -a);
            if (res != -1 && res < n) cout << "fixed point for " << a << ": " << (res + 1)  << "\n";
            else cout << "no fixed point for " << a << "\n";
        }
        cout << "\n";

        count++;
    }

    return 0;
}