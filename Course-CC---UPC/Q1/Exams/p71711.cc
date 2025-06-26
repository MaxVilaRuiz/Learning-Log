#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Matrix;

bool zigazaga(const Matrix& matrix) {
    int last = matrix[0][0];
    for (int i = 0; i < matrix[0].size(); i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < matrix.size(); j++) {
                if (i != 0 or j != 0) {
                    if (matrix[j][i] <= last) return false;
                    last = matrix[j][i];
                }
            }
        }
        else {
            for (int j = matrix.size() - 1; 0 <= j; j--) {
                if (matrix[j][i] <= last) return false;
                last = matrix[j][i];
            }
        }
    }
    return true;
}

int main() {
    int rows, cols, count = 1;
    while (cin >> rows >> cols) {
        Matrix matrix (rows, vector<int> (cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }

        string res;
        if (zigazaga(matrix)) res = "si";
        else res = "no";

        cout << "matriu " << count << ": " << res << endl;
        count++;
    }
}