#include "queue.hh"

int main()
{
  Queue<string> q;
  q.push("a");
  q.push("b");
  q.push("c");
  Queue<string> q2 = q;
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
  cout << q2.front() << endl;
}
