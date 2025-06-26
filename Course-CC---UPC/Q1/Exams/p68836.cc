#include <iostream>
using namespace std;

struct Data {
    int dia, mes, any;
};

bool menor(const Data& d1, const Data& d2) {
    if (d2.any < d1.any) return false;
    else if (d2.any == d1.any) {
        if (d2.mes < d1.mes) return false;
        else if (d2.mes == d1.mes) {
            if (d2.dia <= d1.dia) return false; 
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    char aux;
    Data data1;
    cin >> data1.dia >> aux >> data1.mes >> aux >> data1.any;
    Data data2;
    cin >> data2.dia >> aux >> data2.mes >> aux >> data2.any;
    Data data3;
    cin >> data3.dia >> aux >> data3.mes >> aux >> data3.any;

    bool trobat = false;
    if (menor(data1, data3)) {
        if (menor(data1, data2) and menor(data2, data3)) {
            cout << data2.dia << '/' << data2.mes << '/' << data2.any << endl;
            trobat = true;
        }
        else if (3 == n) cout << "cap data trobada" << endl;
    }
    else {
        if (menor(data3, data2) and menor(data2, data1)) {
            cout << data2.dia << '/' << data2.mes << '/' << data2.any << endl;
            trobat = true;
        }
        else if (3 == n) cout << "cap data trobada" << endl;
    }

    int i = 3;
    while (i < n and not trobat) {
        cin >> data1.dia >> aux >> data1.mes >> aux >> data1.any;
        swap(data3, data1);
        swap(data2, data1);

        if (menor(data1, data3)) {
            if (menor(data1, data2) and menor(data2, data3)) {
                cout << data2.dia << '/' << data2.mes << '/' << data2.any << endl;                    
                trobat = true;
            }
            else if (i == n - 1) cout << "cap data trobada" << endl;
        }
        else {
            if (menor(data3, data2) and menor(data2, data1)) {
                cout << data2.dia << '/' << data2.mes << '/' << data2.any << endl;
                trobat = true;
            }
            else if (i == n - 1) cout << "cap data trobada" << endl;
        }
        
        i++;
    }
}