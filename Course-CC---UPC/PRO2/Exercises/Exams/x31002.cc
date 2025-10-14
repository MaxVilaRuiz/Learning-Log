#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string process_word(const string& w) {
    stack<char> s;
    for (char c : w) {
        if (!s.empty() && abs(s.top() - c) == 32) s.pop();
        else s.push(c);
    }

    string result = "";
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}


int main() {
    string w;
    while (cin >> w) { 
        cout << process_word(w) << endl;
    }

    return 0;
}