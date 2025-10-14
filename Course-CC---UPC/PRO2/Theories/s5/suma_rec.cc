#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int>& v) {
    vector<int> aux = v;
    if (aux.size() == 1) return aux[0];
    else {
        int last = aux[aux.size()-1];
        aux.pop_back();
        return last + sum(aux);
    } 
}

int main() {
    int n;
    cin >> n;

    vector<int> v (n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << sum(v) << endl;
}