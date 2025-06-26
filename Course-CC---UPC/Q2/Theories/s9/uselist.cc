#include "list.hh"

int main()
{
  List<int> l;
  l.push_front(1);
  l.push_back(2);
  l.push_front(3);
  l.push_back(4);
  cout << l << endl;

  List<int>::iterator it = l.begin();
  cout << *it << endl;
	
  List<int>::iterator it2;
  it2 = ++it;
  cout << *it << endl;
  cout << *it2 << endl;
  it2 = it++;
  cout << *it << endl;
  cout << *it2 << endl;
  it2 = --it;
  cout << *it << endl;
  cout << *it2 << endl;
  it2 = it--;
  cout << *it << endl;
  cout << *it2 << endl;
  l.insert(it, 5);
  cout << l << endl;
  it++;
  l.insert(it, 6);
  cout << l << endl;
  it = l.erase(it);
  l.insert(it, 7);
  cout << l << endl;
}
