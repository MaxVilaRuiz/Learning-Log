#include <iostream>
#include <vector>
using namespace std;

int binary_first(double x, const vector<double>& v, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == x) {
            ans = m;
            r = m - 1; 
        }
        else if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return ans;
}

int first_occurrence(double x, const vector<double>& v) {
    int n = v.size();
    if (n == 0) return -1;

    int k = -1;
    for (int i = 1; i < n; ++i) {
        if (v[i] < v[i-1]) {
            k = i;
            break;
        }
    }

    if (k == -1) return binary_first(x, v, 0, n - 1);

    int p1 = binary_first(x, v, 0, k - 1);
    if (p1 != -1) return p1;
    return binary_first(x, v, k, n - 1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}