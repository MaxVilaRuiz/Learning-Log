#include <iostream>
using namespace std;

// Pre: l'entrada consisteix en un nombre natural 'n' i el caràcter 
//      de la primera carta de la seqüència. Seguidament, es demana 
//      introduïr una seqüència de caràcters.
// Post: retorna cert si en la seqüència existeix una carta que s'ha 
//       repetit 'n' cops de manera consecutiva. Altrament, retorna fals.
bool sequencia(int n, char carta1, char& carta_rep) {
    int compt = 1;
    char carta2;

    // Invariant: la variable 'compt' sempre representarà el nombre de 
    // vegades que una carta ha estat introduïda de manera consecutiva.
    while (cin >> carta2) {
        if (carta1 == carta2) compt++;
        else compt = 1;

        if ((compt == n)) {
            carta_rep = carta2;
            return true;
        }

        carta1 = carta2;
    }

    return false;
}

// Pre: l'entrada consisteix en un nombre enter 'n' seguit d'una 
//      seqüència de caràcters que representen les cartes del Poker.
// Post: cal escriure "N-Poker de x!", en el qual 'N' és l'enter que 
//       ha introduit l'usuari i 'x' és la carta que s'ha repetit 'n' 
//       vegades de manera consecutiva en la seqüència. Si cap carta ha 
//       complert la condició anterior, s'escriurà "No hi ha N-Poker". 
int main() {
    int n;
    cin >> n;

    char carta1;
    cin >> carta1;
    char carta_rep = carta1;

    if (n == 1) cout << n << "-Poker de " << carta1 << '!' << endl; 
    else {
        if (sequencia(n , carta1, carta_rep)) 
            cout << n << "-Poker de " << carta_rep << '!' << endl;
        else cout << "No hi ha " << n << "-Poker" << endl;
    }
}