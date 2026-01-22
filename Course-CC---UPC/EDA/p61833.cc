#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

Matrix mult_matrix(const Matrix& a, const Matrix& b) {
    Matrix res(2, vector<int>(2, 0));
    int m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int m2 = (a[1][0] + a[1][1]) * b[0][0];
    int m3 = a[0][0] * (b[0][1] - b[1][1]);
    int m4 = a[1][1] * (b[1][0] - b[0][0]);
    int m5 = (a[0][0] + a[0][1]) * b[1][1];
    int m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    res[0][0] = m1 + m4 - m5 + m7;
    res[0][1] = m3 + m5;
    res[1][0] = m2 + m4;
    res[1][1] = m1 - m2 + m3 + m6;

    return res;
}


int main() {
    Matrix base(2, vector<int>(2, 0));
    Matrix res(2, vector<int>(2, 0));
    int n, m;

    while (cin >> base[0][0] && cin >> base[0][1] && cin >> base[1][0] && cin >> base[1][1]) {
        cin >> n >> m;
        
        res = {{1,0}, {0,1}};
        while (0 < n) {
            if ((n % 2) != 0) res = mult_matrix(res, base);
            base = mult_matrix(base, base);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    res[i][j] %= m;
                    base[i][j] %= m;
                }
            }
            n /= 2;
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (j) cout << " ";
                cout << res[i][j];
            }
            cout << "\n";
        }

        cout << "----------" << "\n";
    }

    return 0;
}