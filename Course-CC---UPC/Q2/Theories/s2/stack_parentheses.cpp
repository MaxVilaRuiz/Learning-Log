#include <iostream>
#include <stack>
using namespace std;

// Pre: True
// Post: Returns True if brackets are balanced within expr string
bool isBalanced(const string &expr) {
  stack<char> s;
  
  for (char ch : expr) {
    if (ch == '(' || ch == '{' || ch == '[') {
      s.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      // Closing bracket without opening
      if (s.empty()) return false; 
      
      // Remove top from the stack
      const char top = s.top();
      s.pop(); 
      
      // Check if brackets match 
      if ((ch == ')' && top != '(') ||
          (ch == '}' && top != '{') ||
          (ch == ']' && top != '[')) {
          return false;
      }
    }
  }
  
  // Stack should be empty if balanced
  return s.empty(); 
}

/*
 * Balanced Parentheses Checker
 *   Input: "{[()()]}"
 *   Output: Balanced
 * 
 *   Input: "{[(])}"
 *   Output: Not Balanced
 * 
 * Hint: Use a stack to push opening brackets and pop 
 *   when encountering a closing bracket.
 */
int main() {
  string testCases[] = {
    "{[()()]}", 
    "{[(])}", 
    "((()))", 
    "[{}]", 
    "({})[", 
    "(()))"
  };
  
  for (const string &expr : testCases) {
    cout << "Expression: " << expr << " -> "
         << (isBalanced(expr) ? "Balanced" : "Not Balanced") << endl;
  }

  return 0; // Program terminated OK!
}