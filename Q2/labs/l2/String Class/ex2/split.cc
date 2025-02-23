#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @fn vector<string> split(string text, string sep)
 *
 * @brief Divide un texto en partes separadas por un separador.
 *
 * Ejemplo: `split("1,2,3", ",")` devuelve `{"1", "2", "3"}`
 *
 * @param text Texto a dividir
 * @param sep Separador
 *
 * @pre: `sep.length() >= 0`. Si `sep` está vacío, se divide cada carácter.
 *
 * @return `vector<string>` Partes del texto
 */
vector<string> split(string text, string sep) {
    vector<string> pieces;

    int start = 0;  // como si hubiera un separador antes del inicio
    int pos = text.find(sep, start);
    while (pos < text.length() && pos != -1) {
        int    tam = sep.empty() ? 1 : pos - start;
        string piece = text.substr(start, tam);

        pieces.push_back(piece);

        start = pos + (sep.empty() ? 1 : sep.length());
        pos = text.find(sep, start);
    }
    if (start < text.length()) {
        pieces.push_back(text.substr(start));
    }
    return pieces;
}


/**
 * @fn string join(vector<string> v, string sep)
 * 
 * @brief Junta tots els elements d'un vector de string, amb un
 * separador entre mig, en un string resultant.
 * 
 * Exemple: `join(split("a; b; c; d", "; "), "; ")` retorna `a; b; c; d`
 * 
 * @param v Vector que cal unificar
 * @param sep Separador que s'afegirà entremig de cada element del vector
 * 
 * @pre: `sep.length() >= 0`. Altrament, el string resultant serà la unió
 *        directa dels elements del vector.
 * 
 * @return: `string` Vector unificar amb separadors inclosos.
*/
string join(vector<string> v, string sep) {
    string res = "";
    for (int i = 0; i < v.size(); i++) {
        res += v[i];
        if ((i + 1) != v.size()) res += sep;
    }
    return res;
}


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{";
    if (!v.empty()) {
        out << v[0];
        for (int i = 1; i < v.size(); i++) {
            out << ", " << v[i];
        }
    }
    return out << "}";
}