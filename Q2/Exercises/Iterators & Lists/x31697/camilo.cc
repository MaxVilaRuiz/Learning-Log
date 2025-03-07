#include <list>
#include <string>
using namespace std;

void inserta_don(list<string>& texto) {
    string word = "Don";
    list<string>::iterator it = texto.begin();
    while (it != texto.end()) {
        if ((*it) == "Camilo") {
            texto.insert(it, word);
        }
        it++;
    }
}