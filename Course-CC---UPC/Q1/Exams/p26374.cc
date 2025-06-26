#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matriu;
 	
Matriu suma(const Matriu& a, const Matriu& b) {
    Matriu sum(a.size(), vector<int> (a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            sum[i][j] = a[i][j] + b[i][j];
        } 
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    Matriu matrix1(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
    Matriu matrix2(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }

    Matriu res = suma(matrix1, matrix2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}