#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int num;
        cin >> num;
        int maxim = num;

        for (int i = 1; i < n; i++) {
            cin >> num;
            if (num > maxim) maxim = num;
        }

        cout << maxim << endl;
    }
}