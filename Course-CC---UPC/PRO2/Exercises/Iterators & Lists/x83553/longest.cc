
#include <list>
#include <string>
using namespace std;

list<string>::const_iterator longest(const list<string>& text) {
    if (text.empty()) return text.end();

    list<string>::const_iterator it = text.begin();
    list<string>::const_iterator res;
    int tamany = 0;
    while (it != text.end()) {
        if (tamany < (*it).size()) {
            tamany = (*it).size();
            res = it;
        }
        it++;
    }
    return res;
}