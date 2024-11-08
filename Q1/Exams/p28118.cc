#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double distancia(double x1, double y1, double x2, double y2) {
    double op1 = (x1 - x2) * (x1 - x2);
    double op2 = (y1 - y2) * (y1 - y2);
    double suma = op1 + op2;
    double arrel = sqrt(suma);

    return arrel;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    string paraula;
    while (cin >> paraula) {
        double x1, y1, x2, y2, recorregut = 0;
        cin >> x1 >> y1;
        double x1_ini = x1, y1_ini = y1;
        while ((cin >> x2 >> y2) and ((x2 != x1_ini) or (y2 != y1_ini))) {
            recorregut += distancia(x1, y1, x2, y2);
            x1 = x2;
            y1 = y2;
        }
        recorregut += distancia(x1, y1, x1_ini, y1_ini);
        cout << "Trajecte " << paraula << ": " << recorregut << endl;
    }
}