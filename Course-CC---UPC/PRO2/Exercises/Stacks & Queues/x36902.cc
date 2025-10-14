#include <iostream>
#include <stack>
using namespace std;

int main() {
    string sequence;
    cin >> sequence;
    stack<char> s;
    int count = 0;
    int error = 0;
    bool fita = false;
    while (count < sequence.length() && !fita) {
        if (sequence[count] == '(' || sequence[count] == '[') 
            s.push(sequence[count]);
        else if (sequence[count] == ')' || sequence[count] == ']') {
            if ((sequence[count] == ')' && s.top() == '(') ||
                (sequence[count] == ']' && s.top() == '[')) s.pop();
            else {
                error = count + 1;
                fita = true;
            }
        }
        else { // sequence[count] == '.'
            if (0 < s.size() && (s.top() == '(' || s.top() == '[')) error = count;
        }
        count++;
    }

    error == 0 ? cout << "Correcte" << endl : 
                cout << "Incorrecte " << error << endl;
}