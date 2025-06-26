#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim(const vector<double>& v, int m) {
    double max = v[0];
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        if (v[i] > max) {
            pos = i;
            max = v[i];
        }
    }
    
    return pos;
}

int main() {
    int n;
    cin >> n;

    vector<double> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int m;
    cin >> m;
    cout << posicio_maxim(v, m);
}