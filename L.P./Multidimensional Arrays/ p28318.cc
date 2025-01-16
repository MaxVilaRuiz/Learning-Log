#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    typedef vector< vector<int> > matrix;
    matrix matriu(n, vector<int>(m,0));
    for (int i = 0; i < matriu.size(); i++) {
        for (int j = 0; j < matriu[0].size(); j++)
            cin >> matriu[i][j];
    }

    string consulta;
    while (cin >> consulta) {
        if (consulta == "fila") {
            cin >> n;
            cout << "fila " << n << ':';
            for (int i = 0; i < matriu[0].size(); i++)
                cout << ' ' << matriu[n-1][i];
        }
        else if (consulta == "columna") {
            cin >> n;
            cout << "columna " << n << ':';
            for (int i = 0; i < matriu.size(); i++)
                cout << ' ' << matriu[i][n-1];
        }
        else if (consulta == "element") {
            cin >> n >> m;
            cout << "element " << n << ' ' << m <<  ": ";
            cout << matriu[n-1][m-1];
        }
        cout << endl;
    }
}