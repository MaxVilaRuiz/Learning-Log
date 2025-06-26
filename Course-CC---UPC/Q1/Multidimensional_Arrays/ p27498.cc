#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

void transpose(Matrix& m) {
    for (int i = 0; i < (m.size() - 1); i++) {
        for (int j = 0; j < m.size(); j++) {
            if (j > i) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Matrix matriu(n, vector<int> (n, 0));
    for (int i = 0; i < matriu.size(); i++) {
        for (int j = 0; j < matriu.size(); j++) 
            cin >> matriu[i][j];
    }
    transpose(matriu);

    for (int i = 0; i < matriu.size(); i++) {
        for (int j = 0; j < matriu.size(); j++)
            cout << matriu[i][j];
        cout << endl;
    }
}