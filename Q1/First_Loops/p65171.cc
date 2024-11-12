#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    double n, num, sumatori1 = 0, sumatori2 = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        sumatori1 += (num * num);
        sumatori2 += num;
    }

    sumatori1 *= (1 / (n - 1));
    sumatori2 = (1 / (n * (n - 1))) * (sumatori2 * sumatori2);
    cout << sumatori1 - sumatori2 << endl;
}