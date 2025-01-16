#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    while (esq <= dre) {
        int i = (esq + dre) / 2;
        if (x < v[i]) dre = i - 1;
        else if (x > v[i]) esq = i + 1;
        else return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<double> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    double x;
    cin >> x;

    cout << posicio(x, v, 0, n - 1) << endl;
}