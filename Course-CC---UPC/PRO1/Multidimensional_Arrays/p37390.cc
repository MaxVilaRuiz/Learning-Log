#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b) {
    Matrix res(a.size(), vector<int> (a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            int sum = 0;
            for (int w = 0; w < a.size(); w++) {
                sum += a[i][w] * b[w][j];
            }
            res[i][j] = sum;
        }

    }

    return res;
}

int main() {
    int n;
    cin >> n;
    Matrix matriu1(n, vector<int> (n, 0));
    for (int i = 0; i < matriu1.size(); i++) {
        for (int j = 0; j < matriu1.size(); j++) 
            cin >> matriu1[i][j];
    }

    Matrix matriu2(n, vector<int> (n, 0));
    for (int i = 0; i < matriu2.size(); i++) {
        for (int j = 0; j < matriu2.size(); j++) 
            cin >> matriu2[i][j];
    }

    Matrix res = product(matriu1, matriu2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.size(); j++)
            cout << res[i][j];
        cout << endl;
    }
}