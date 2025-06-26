#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 * Example 1
 */
void print_stack_iter(stack<string> s) {
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}

/*
 * Example 2
 */
void print_stack_rec(stack<string> s) {
  // Base case
  if (s.empty()) return;
  // General case (or recursive case)
  string top = s.top();
  s.pop();
  print_stack_rec(s);
  cout << top << endl;
}

/*
 * Example 3
 */
stack<string> reverse_stack(stack<string> s) {
  stack<string> saux;
  while (!s.empty()) {
    saux.push(s.top());
    s.pop();
  }
  return saux;
}

/*
 * General Stack Usage
 */
int main() {
  stack<string> s;
  s.push("a");  // s: a
  s.push("b");  // s: a,b
  s.push("c");  // s: a,b,c
  cout << s.top() << endl;   // output: c
  cout << s.size() << endl;  // output: 3
  cout << s.empty() << endl; // output: 0
  s.pop();      // s: a,b
  s.push("d");  // s: a,b,d
  cout << s.top() << endl;   // output: d
  s.pop();      // s: a,b
  s.pop();      // s: a
  s.pop();      // s:
  cout << s.size() << endl;  // output: 0
  cout << s.empty() << endl; // output: 1
}