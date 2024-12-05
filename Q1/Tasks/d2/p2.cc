#include <iostream>
using namespace std;

// PRE: L'entrada comença amb un número natural 'n', seguit d’una seqüència de 'n'
//      quartets d’enters "x1", "y1", "x2" i "y2" que representen el parell de punts
//      (x1, y1) i (x2, y2), en què (x1, y2) és diferent de (x2, y2).
// POST: Per cada parell de punts de la seqüència d’entrada, cal escriure el sentit 
//       en què s’avança quan ens traslladem de (x1, y1) a ( x2, y2). El resultat de
//       cada sortida a de coincidir amb alguna de les següents: 'N' si avança al sord,
//       'S' si avança al sud, 'E' si avança l'est, 'O' si avança a l'oest, "NE" si
//       avança al nord-est, "NO" si avança al nord-oest, "SE" si avança al sud-est i 
//       "SO" si avança al sud-oest.

int main() {
    int n;
    cin >> n;

    int contador = 0; // Per a contar el nombre de cops que cal demanar les entrades.
    int x1, y1, x2, y2;
    // Inv: contador <= n.
    while (contador < n) {
        cin >> x1 >> y1 >> x2 >> y2;  

        // Conjunt de condicionals per saber el sentit en el qual s'avança. 
        if ((x1 == x2) and (y1 < y2)) cout << 'N' << endl;
        else if ((x1 == x2) and (y1 > y2)) cout << 'S' << endl;
        else if ((x1 < x2) and (y1 == y2)) cout << 'E' << endl;
        else if ((x1 > x2) and (y1 == y2)) cout << 'O' << endl;
        else if ((x1 < x2) and (y1 < y2)) cout << "NE" << endl;
        else if ((x1 > x2) and (y1 < y2)) cout << "NO" << endl;
        else if ((x1 < x2) and (y1 > y2)) cout << "SE" << endl;
        else if ((x1 > x2) and (y1 > y2)) cout << "SO" << endl;

        contador += 1;
    }
}