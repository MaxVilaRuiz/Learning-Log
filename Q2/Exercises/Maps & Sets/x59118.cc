#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, string> M;
    pair<string, string> pairs;

    string line;
    getline(cin, line);;
    string word = "";
    while (line != "") {
        bool firstWord = true;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ') word += line[i];
            else {
                if (firstWord) pairs.first = word;
                else pairs.second = word;
                word = "";
                firstWord = false;
            }

            if (i + 1 == line.length()) {
                pairs.second = word;
                word = "";
            }
        }
        
        M[pairs.first] = pairs.second;
        getline(cin, line);
    }

    while (cin >> word) {
        if (M.count(word)) cout << M[word] << endl;
        else cout << "<not found>" << endl;
    }
}