#include <iostream>
#include <sstream>
#include <stack>
#include "html_elem.hh"
using namespace std;

/**
 * @brief Determina si una seqüència de paraules és una pàgina HTML correcta
 * 
 * @param in Un `stream` d'entrada d'on llegir les paraules
 * @returns `true` si la seqüència llegida de `in` és una pàgina HTML, `false` altrament.
 */
bool is_correct_html(istream& in) {
    string word;
    stack<string> s;
    bool first = true;
    bool fi = false;
    // Llegeix cada paraula del canal d'entrada `in` mentre es pugui
    while (in >> word) {
        if (!fi) {
            if (first) {
                if (is_tag(word) && !is_close_tag(word) && tag_name(word) == "html") {
                    s.push(tag_name(word));
                    first = false;
                }
                else return false;
            }
            else if (is_tag(word) && !is_close_tag(word) && tag_name(word) == "html") return false;
            else if (is_close_tag(word) && tag_name(word) == "html") {
                if (0 < s.size() && s.top() == tag_name(word)) {
                    s.pop();
                    fi = true;
                }
            }
            else if (is_tag(word) && !is_close_tag(word)) s.push(tag_name(word));
            else if (is_close_tag(word)) {
                if (0 < s.size() && s.top() == tag_name(word)) s.pop();
                else return false;
            }
        }
        else return false;
    }

    return true;
}


int main() {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        cout << (is_correct_html(iss) ? "HTML" : "text") << endl;
    }
    return 0;
}
