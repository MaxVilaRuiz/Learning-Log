#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stack<char> data;
        bool error = false;
        int count = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(' || line[i] == '[') data.push(line[i]);
            else if (0 < data.size()) {
                if (line[i] == ')' && data.top() == '(') data.pop();
                else if (line[i] == ']' && data.top() == '[') data.pop();
                else {
                    data.pop();
                    count++;
                    error = true;
                }
            }
        }

        if (!error) cout << data.size() << endl;
        else cout << count << endl;
    }
}