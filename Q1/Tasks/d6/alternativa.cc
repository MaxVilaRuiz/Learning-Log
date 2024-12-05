#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

// Pre: L'entrada consisteix en una matriu quadràtica 
//      formada per nombres enters.
// Post: Ha de retornar "true" si la matriu és doblement 
//       estocàstica i "false" altrament.
string doubly_stochastic(const Matrix& matrix) {
    int size = matrix.size();

    for (int row = 0; row < size; row++) {
        int sum_rows = 0, sum_cols = 0;
        for (int col = 0; col < size; col++) {
            sum_rows += matrix[row][col];
            sum_cols += matrix[col][row];
        }

        if (sum_rows != 10 or sum_cols != 10) return "false";
    }

    return "true";
}

// Pre: L'entrada consisteix en una seqüència sense sentinella 
//      de nombres enters seguits dels valors de cada posició 
//      d'una matriu quadràtica nxn.
// Post: Mostra el resultat de la funció "doubly_stochastic()".
int main() {
    int n;
    while (cin >> n) {
        Matrix matrix(n, vector<int> (n, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cin >> matrix[row][col];
            }
        }

        cout << doubly_stochastic(matrix) << endl;
    }
}