#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

void min_max(const Matrix& mat, int& minimum, int& maximum) {
    minimum = mat[0][0];
    maximum = mat[0][0];
    for (int row = 0; row < mat.size(); row++) {
        for (int col = 0; col < mat[0].size(); col++) {
            if (mat[row][col] < minimum) minimum = mat[row][col];
            else if (mat[row][col] > maximum) maximum = mat [row][col];
        }
    }
}

int main() {
    int rows, cols, diff = 0, count_res = 1, count = 1;
    while (cin >> rows >> cols) {
        Matrix matrix (rows, vector<int> (cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cin >> matrix[i][j];
        }

        int min, max;
        min_max(matrix, min, max);
        if (diff < (max - min)) {
            diff = max - min;
            count_res = count;
        }
        count++;
    }

    cout << "la diferencia maxima es " << diff << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << count_res << endl;
    return 0;
}