#include <iostream>
#include "html_elem.hh"
#include "vstack.hh"
using namespace std;

// Pre: Seqüència de strings, els quals representen etiquetes d'HTML o paraules qualsevol.
// Post: Es mostra la mateixa seqüència, però eliminants les paraules dins de les etiquetes 
//       "<script>" sempre que aquesta no sigui fill directe de l'etiqueta "<head>" i, alhora, 
//       que aquesta última ho sigui de l'etiqueta "<html>".
int main() {
    VStack pila;
    string s;
    while (cin >> s) {
        if (is_tag(s)) {
            if (is_close_tag(s)) {
                pila.pop();
                cout << s << ' ';
            }
            else {
                pila.push(s);  
                cout << s << ' ';
            }
        }
        else {
            if (0 < pila.size() && tag_name(pila.top(0)) == "script") {
                if (1 < pila.size() && tag_name(pila.top(-1)) == "head") {
                    if (2 < pila.size() && tag_name(pila.top(-2)) == "html") {
                        cout << s << ' ';
                    }
                }
            }
            else cout << s << ' ';
        }
    }
}