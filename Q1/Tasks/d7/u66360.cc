#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;

// Pre: L'entrada consisteix en dues matrius d'igual mida, però diferents valors.
// Post: Calcula la suma de la primera matriu des de la posició [0][0] fins a la posició 
//       [i][j] (en funció de la iteració) i guarda el resultat en la segona matriu. 
void compute_prefixSum(const Matrix& matrix, Matrix& prefix_matrix) {
    for (int row = 0; row < prefix_matrix.size(); row++) {
        for (int col = 0; col < prefix_matrix[0].size(); col++) {
            prefix_matrix[row][col] = matrix[row][col];
            if (row > 0) prefix_matrix[row][col] += prefix_matrix[row - 1][col];
            if (col > 0) prefix_matrix[row][col] += prefix_matrix[row][col - 1];
            if (row > 0 and col > 0) 
                prefix_matrix[row][col] -= prefix_matrix[row - 1][col - 1];
        }
    }
}

// Pre: L'entrada consisteix en una matriu seguida de 4 nombres enters que representen 
//      els punts de la cantonada superior esquerra i de la cantonada inferior dreta 
//      d'una submatriu que es vol determinar.
// Post: Retorna la suma dels elements de la submatriu.
int submatrix_sum(const Matrix& prefix_matrix, int x1, int y1, int x2, int y2) {
    int sum = prefix_matrix[x2][y2];
    if (x1 > 0) sum -= prefix_matrix[x1 - 1][y2];
    if (y1 > 0) sum -= prefix_matrix[x2][y1 - 1];
    if (x1 > 0 and y1 > 0) sum += prefix_matrix[x1 - 1][y1 - 1];

    return sum;
}

// Pre: L'entrada consisteix en una matriu, dos nombres enters que representen el 
//      nombre de files i columnes de la matriu; un altre nombre enter que defineix 
//      la mida de la submatriu quadràtica que representa la zona de cerca i quatre 
//      enters més que s'usen per a emmagatzemar els càlculs del procediment.
// Post: Calcula suma de la submatriu amb els valors més alts, l'element més gran 
//       d'aquesta matriu i el punt superior esquerra en el qual es troba aquesta 
//       submatriu en la matriu original.
void findZone(const Matrix& matrix, int n, int m, int k, int& bestRow, int& bestCol,
                int& maxSum, int& maxDensity) {
    Matrix prefix_matrix (n, vector<int>(m, 0));
    compute_prefixSum(matrix, prefix_matrix);

    maxSum = -1;
    maxDensity = -1;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= m - k; ++j) {
            int x1 = i, y1 = j;
            int x2 = i + k - 1, y2 = j + k - 1;
            int sum = submatrix_sum(prefix_matrix, x1, y1, x2, y2);

            int density = -1;
            for (int x = x1; x <= x2; ++x) {
                for (int y = y1; y <= y2; ++y)
                    if (density < matrix[x][y]) density = matrix[x][y];
            }

            if ((sum > maxSum) or (sum == maxSum and i < bestRow)) {
                maxSum = sum;
                maxDensity = density;
                bestRow = i;
                bestCol = j;
            }
        }
    }
}

// Pre: L'entrada consisteix en dos nombres enters que representen el nombre de files
//      i columnes que té la matriu que es demana seguidament. 
// Post: Mostra per pantalla el punt superior esquerra de la submatriu amb els valors 
//       més alts en la matriu original, la suma dels elements d'aquesta submatriu i 
//       el seu element més gran.
int main() {
    int n, m;
    while (cin >> n >> m and n != 0) {
        Matrix matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j];
        }

        int k;
        cin >> k;

        int bestRow = -1, bestCol = -1, maxSum, maxDensity;
        findZone(matrix, n, m, k, bestRow, bestCol, maxSum, maxDensity);

        cout << '(' << bestRow << "," << bestCol << ')' << endl;
        cout << maxSum << endl;
        cout << maxDensity << endl;
    }

    return 0;
}