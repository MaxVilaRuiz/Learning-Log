#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> garbellEratostenes() {
    vector<bool> primer(4000000 + 1, true);
    primer[0] = primer[1] = false;

    for (int p = 2; p * p <= 4000000; ++p) {
        if (primer[p]) {
            for (int i = p * p; i <= 4000000; i += p) {
                primer[i] = false;
            }
        }
    }

    return primer;
}

int potencia(int num, int potencia) {
    int res = 1;
    for (int i = 0; i < potencia; i++) {
        res *= num;
    }
    return res;
}

int cod_godel(const vector<bool>& v, string num) {
    int prod = 1, pos = 2;
    for(int i = 0; i < num.size(); i++) {
        bool trobat = false;
        while (not trobat) {
            if (v[pos]) trobat = true;
            pos++;
        }
        prod *= potencia(pos - 1, num[i] - '0');
    }

    return prod;
}

int main() {
    string num;
    while (cin >> num) {
        cout << num << " -> ";
        cout << cod_godel(garbellEratostenes(), num) << endl;
    }
} 