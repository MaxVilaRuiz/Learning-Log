#include <iostream>
using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("queue.hh")
#include "queue.hh"
#endif
#endif

int main() {
	Queue<string> q;
	string command, x;
	while (cin >> command) {
		if (command == "push") {
			cin >> x;
			q.push(x);
		} else if (command == "pop") {
			q.pop();
		} else if (command == "front") {
			cout << q.front() << endl;
		} else if (command == "size") {
			cout << q.size() << endl;
		} else if (command == "rotate") {
			cin >> x;
			q.rotate(x);
		} else if (command == "print") {
			cout << q << endl;
		}
	}
}
