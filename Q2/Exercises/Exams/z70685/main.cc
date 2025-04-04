#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

/**
 * @brief Retorna un nou string amb les lletres de
 *        `s` ordenades
 *
 * @param  s  un `string`
 * @returns Un nou string amb les lletres de `s` ordenades
 */
string sort_chars(string s) {
    string sorted = s;
    sort(sorted.begin(), sorted.end());
    return sorted;
}

// Pre: L'entrada consisteix en una sequencia de strings sense sentinella.
// Post: Es mostra per pantalla una linia per a cada grup de paraules 
//       (ordenat lexicogràficament) que s'han trobat en la sequencia que 
//       comparteixen les mateixes lletres i la mateixa mida.
int main() {
    map<string, set<string> > M; 
    string word;
    while (cin >> word) {
        M[sort_chars(word)].insert(word);
    }

    auto it = M.begin();
    while (it != M.end()) {
        if (1 < (*it).second.size()) {
            auto it2 = (*it).second.begin();
            while (it2 != (*it).second.end()) {
                if (it2 != (*it).second.begin()) cout << ' ';
                cout << *it2;
                it2++;
            }
            cout << endl;
        }
        it++;
    }
}