#include <iostream>
#include "html_elem.hh"
#include "vstack.hh"
using namespace std;

int main() {
    string s;
    VStack pila;
    int count_open = 0;
    while (cin >> s) {
        pila.push(s);
        // if (is_tag(s) && !is_close_tag(s)) {
        //     count_open++; 
        // }
    }
    cout << pila.top(5) << endl;
}