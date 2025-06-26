#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

bool ziga_zaga(const Matrix& matriu) {
    int last = matriu[0][0];
    for (int col = 0; col < matriu[0].size(); col++) {
        for (int row = 1; row < matriu.size(); row++) {
            if (last >= matriu[row][col])
                return false;
            last = matriu[row][col];
        }
    }
    
    return true;
}

void read_matrix(Matrix& matriu) {
    for (int i = 0; i < matriu.size(); i++)
        for (int j = 0; j < matriu[0].size(); j++) 
            cin >> matriu[i][j];
}

int main() {
    int rows, cols, compt = 1;
    while (cin >> rows >> cols) {
        Matrix matriu (rows, vector<int> (cols, 0));
        read_matrix(matriu);

        cout << "matriu " << compt;
        if (ziga_zaga(matriu)) cout << ": si" << endl;
        else cout << ": no" << endl;

        compt++;
    }
}