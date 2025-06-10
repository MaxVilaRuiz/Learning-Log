#include <iostream>
#include <sstream>
using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("stack.hh")
#include "stack.hh"
#endif
#endif

int main() {
	Stack<int> S;
	string line;

	while (getline(cin, line)) {
		if (line.empty() || line[0] == '#') {
			// Skip line starting with '#' (comment) or empty
		} else {
			istringstream sin(line);
			string command;
			int x;

			sin >> command;
			if (command == "push") {
				sin >> x;
				S.push(x);
			} else if (command == "pop") {
				S.pop();
			} else if (command == "push_sort") {
				sin >> x;
				S.push_sort(x);
			} else if (command == "size") {
				cout << "size is " << S.size() << endl;
			} else if (command == "print") {
				S.print();
			}
		}
	}
}
