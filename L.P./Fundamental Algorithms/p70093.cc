#include <iostream>
#include <vector>
using namespace std;

vector<double> fusio(const vector<double>& v1, const vector<double>& v2) {
    vector<double> v;
    int i1 = 0, i2 = 0;
    while (i1 < v1.size() and i2 < v2.size()) {
        if (v1[i1] <= v2[i2]) {
            v.push_back(v1[i1]);
            i1++;
        }
        else if (v2[i2] < v1[i1]) {
            v.push_back(v2[i2]);
            i2++;
        }
    }

    while(i1 < v1.size()) {
        v.push_back(v1[i1]);
        i1++;
    }
    while(i2 < v2.size()) {
        v.push_back(v2[i2]);
        i2++;
    }

    return v;
}


int main() {
    int n1;
    cin >> n1;
    vector<double> v1(n1);
    for (int i = 0; i < n1; i++) cin >> v1[i];

    int n2;
    cin >> n2;
    vector<double> v2(n2);
    for (int i = 0; i < n2; i++) cin >> v2[i];

    vector<double> res = fusio(v1, v2);
    for (int i = 0; i < res.size(); i++) cout << res[i];
}