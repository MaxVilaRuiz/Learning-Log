#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stack<char> data;
        vector<int> longest;
        bool fi = false;
        int i = 0;
        while (i < line.length() && !fi) {
            if (line[i] == '(' || line[i] == '[') {
                data.push(line[i]);
                longest.push_back(i);
            }
            else if (0 < data.size()) {
                if (line[i] == ')' && data.top() == '(') {
                    data.pop();
                    longest.pop_back();
                }
                else if (line[i] == ']' && data.top() == '[') {
                    data.pop();
                    longest.pop_back();
                }
                else fi = true;
            }
            else longest.push_back(i);
            i++;
        }

        if (0 < longest.size()) cout << longest[0] << endl;
        else cout << line.length() << endl;
    }
}