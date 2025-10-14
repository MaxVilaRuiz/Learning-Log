#include "stack.hh"

typedef long long int ll;

int main() {
  Stack<string> s;
  s.push("a");
  s.push("b");
  s.push("c");

	Stack<string> s1(s);

  Stack<string> s2 = s;
	
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s2.top() << endl;

  Stack<string> s3, s4, s5, s6;

  s3 = (s4 = (s5 = (s6 = s)));

  (s3 = s4) = s5;
}
