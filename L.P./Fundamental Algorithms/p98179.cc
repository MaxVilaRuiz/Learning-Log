#include <iostream>
#include <vector>
using namespace std;

void insert(vector<double>& v) {
    int i = v.size() - 1;
    while (0 < i and v[i] < v[i - 1]) {
        swap(v[i], v[i - 1]);
        i--;
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
    insert(v);

    for (int i = 0; i < n; i++)
        cout << v[i];
    cout << endl;
}