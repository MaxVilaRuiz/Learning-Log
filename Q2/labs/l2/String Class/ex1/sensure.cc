#include <iostream>
#include <sstream>
#include <string>
using namespace std;


/*

*/
void sensure(string& text, const string& word) {
    int pos = text.find("trumped", 0);
    while (pos != -1) {
        text.replace(pos, word.size(), "[redacted]");
        pos = text.find("trumped", pos+1);
    }
}


int main() {
    string text = "";
    getline(cin, text);
    sensure(text, "trumped");

    cout << text << endl;

    return 0;
}