#include <iostream>
using namespace std;

void rectangle(int n, int m) {
    int output = 9;
    for (int j = 0; j < n; j++) {
        for (int w = 0; w < m; w++) {
            cout << output;
            output--;
            if (output == -1) output = 9;
        }
        cout << endl;
    }
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    for (int i = 0; i < k; i++) {
        rectangle(n, m);
        if (i != (k - 1)) cout << endl;

    }
}