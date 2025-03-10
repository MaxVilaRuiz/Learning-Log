#include <iostream>
#include <string>
using namespace std;

string reverse_string(string s) {
    if (s.size() == 0) {
        return "";
    }
    else {
        string res = "";
        res += s[s.length()-1];
        res += reverse_string(s.erase(s.length()-1));
        return res;
    }
}

bool palindrome(const string& word, int i, int j) {
    if (i == j) return true;
    else if (i+1 == j) return word[i] == word[j];
    else {
        if (word[i] != word[j]) return false;
        else return palindrome(word, i+1, j-1);
    }
}  

// Pre: 0 <= i <= j <= n (being n = word.length() - 1)
bool is_palindrome(const string& word) {
    return palindrome(word, 0, word.length() - 1);
} 

int main() {
    string word;
    cin >> word;

    cout << is_palindrome(word) << endl;
}