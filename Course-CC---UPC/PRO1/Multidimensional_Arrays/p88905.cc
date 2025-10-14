#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b) {
    int rows = a.size();
    int columns = b[0].size();
    Matrix matrix(rows, vector<int> (columns, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int sum = 0;
            for (int w = 0; w < b.size(); w++) {
                sum += a[i][w] * b[w][j];
            }
            matrix[i][j] = sum;
        }

    }
    
    return matrix;
}

int main() {
    int p, q, r;
    while (cin >> p >> q >> r) {
        Matrix A(p, vector<int>(q));
        Matrix B(q, vector<int>(r));
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < q; ++i) {
            for (int j = 0; j < r; ++j) {
                cin >> B[i][j];
            }
        }
        Matrix C = product(A, B);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < r; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}