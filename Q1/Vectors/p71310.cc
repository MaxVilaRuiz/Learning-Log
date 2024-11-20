#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {
    int n = u.size();
    double result = 0;
    for (int i = 0; i < n; i++)
        result += (u[i] * v[i]);

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<double> u(n);
    vector<double> v(n);
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int j = 0; j < n; j++)
        cin >> v[j];
    
    cout << scalar_product(u, v) << endl;
}