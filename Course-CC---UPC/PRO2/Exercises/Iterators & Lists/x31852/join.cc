#include <iostream>
#include <vector>
using namespace std;

string join(vector<string>::iterator begin, 
            vector<string>::iterator end, string sep) {
    string res = (*begin);
    begin++;

    while (begin != end) {
        res += sep;
        res += (*begin);
        begin++;
    }

    return res;
}