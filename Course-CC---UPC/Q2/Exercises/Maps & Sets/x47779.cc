#include <iostream>
#include <map>
using namespace std;

string to_morse(string s, const map<char,string>& M) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != ' ') {
            if (96 < int(c) && int(c) < 123) c -= ' ';
            if (0 < i) res += " ";
            res += M.at(c);
        }
    }
    return res;
}

int main() {
    map<char, string> M;
   M['A'] = ".-";   M['B'] = "-..."; M['C'] = "-.-."; M['D'] = "-..";
   M['E'] = ".";    M['F'] = "..-."; M['G'] = "--.";  M['H'] = "....";
   M['I'] = "..";   M['J'] = ".---"; M['K'] = "-.-";  M['L'] = ".-..";
   M['M'] = "--";   M['N'] = "-.";   M['O'] = "---";  M['P'] = ".--.";
   M['Q'] = "--.-"; M['R'] = ".-.";  M['S'] = "...";  M['T'] = "-";
   M['U'] = "..-";  M['V'] = "...-"; M['W'] = ".--";  M['X'] = "-..-";
   M['Y'] = "-.--"; M['Z'] = "--..";
   M['0'] = "------"; M['1'] = ".-----"; M['2'] = "..---"; M['3'] = "...--";
   M['4'] = "....-";  M['5'] = ".....";  M['6'] = "-...."; M['7'] = "--...";
   M['8'] = "---..";  M['9'] = "----.";

   string s;
   getline(cin, s);
   cout << to_morse(s, M) << endl;  
}