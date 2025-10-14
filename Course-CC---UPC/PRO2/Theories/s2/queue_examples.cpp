#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
 * Example 1
 */
void read_queue_print_queue() {
  int x;
  queue<int> q;
  while (cin >> x) {
    q.push(x);
  }
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

/*
 * Example 2
 */
void reverse_queue(queue<int>& q) {
  // Base case
  if (q.empty()) return;
  // General case
  int front = q.front();
  q.pop();
  reverse_queue(q); // Recursive call
  q.push(front); // Push in reverse order
}

/*
 * General Queue Usage
 */
int main() {
  queue<string> q;
  q.push("a");  // q: a
  q.push("b");  // q: a,b
  q.push("c");  // q: a,b,c
  cout << q.front() << endl;  // output: a
  cout << q.size() << endl;   // output: 3
  cout << q.empty() << endl;  // output: 0
  q.pop();      // q: b,c
  q.push("d");  // q: b,c,d
  cout << q.front() << endl;  // output: b
  q.pop();      // q: c,d
  q.pop();      // q: d
  q.pop();      // q:
  cout << q.size() << endl;   // output: 0
  cout << q.empty() << endl;  // output: 1
}