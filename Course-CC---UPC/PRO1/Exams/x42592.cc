#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findDistance(int d, const vector<int> &v) {
    int left = 0, right = v.size();
    while (left <= right) {
        int mid = (left + right) / 2;

        int distance = abs(v[mid] - v[mid + 1]);
        if (d < distance) right = mid - 1;
        else if (distance < d) left = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];

    int d; 
    while (cin >> d) cout << findDistance(d, v) << endl;
}