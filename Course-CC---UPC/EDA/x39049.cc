#include <vector>
#include <iostream>
using namespace std;

vector<int> compose(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); i++) res[i] = a[b[i]];
    return res;
}

int main() {
    int n, k; 

    while (cin >> n) {
        vector<int> base(n);
        for (int i = 0; i < n; i++) cin >> base[i];
        cin >> k;

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = i;
        while (k > 0) {
            if ((k % 2) != 0) res = compose(res, base);
            base = compose(base, base);
            k /= 2;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << "\n";
    }

    return 0;
}