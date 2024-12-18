#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Pre: L'entrada consisteix en dos strings.
// Post: La funció retorna "true" si la variable "num1" és més 
//       petita que "num2", altrament retorna false.
bool is_smaller(const string& num1, const string& num2) {
    if (num1.size() != num2.size()) 
        return num1.size() < num2.size();
    return num1 < num2;
}

// Pre: L'entrada consisteix en un vector de string i un string.
// Post: La funció retorna la primera posició del vector tal que v[pos] < z.
int first_position(const vector<string>& v, const string& z) {
    int left = 0, right = v.size() - 1;
    int pos = -1; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (not is_smaller(v[mid], z)) {
            pos = mid; 
            right = mid - 1;
        } 
        else left = mid + 1;
    }
    return pos;
}

// Pre: L'entrada consisteix en un vector de strings buit.
// Post: El procediment emplena el vector amb els valor de l'entrada.
void read_vector(vector<string>& v) {
    for (int i = 0; i < v.size(); i++) 
        cin >> v[i];
}

// Pre: L'entrada consisteix en un nombre "n" seguit de "n" nombres. 
//      A més, s'inicia una seqüència sense sentinella de nombres.
// Post: Es mostra per pantalla la primera posició del vector en què cada
//       nombre "z" és menor al valor d'aquella posició del vector.
int main() {
    int n;
    cin >> n; 

    vector<string> v(n);
    read_vector(v);

    string z;
    while (cin >> z) 
        cout << first_position(v, z) << endl;

    return 0;
}