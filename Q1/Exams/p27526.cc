#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Matriu;

void intercanvia(Matriu& mat, int j, int k) {
    for (int i = 0; i < mat.size(); i++) {
        swap(mat[i][j], mat[i][k]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Matriu matrix(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // First output
    cout << "-----" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
            if (j != m - 1) cout << ' ';
        }
        cout << endl;
    }
    cout << "-----" << endl;

    int j, k;
    while (cin >> j >> k) {
        intercanvia(matrix, j, k);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                cout << matrix[row][col];
                if (col != m - 1) cout << ' ';
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }
}