#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person {
  public:
    string firstname, lastname;
    Person() {}
    Person(string firstname, string lastname) {
      this->firstname = firstname;
      this->lastname = lastname;
    }
  private:
};

bool operator<(Person p1, Person p2) {
  if (p1.lastname != p2.lastname)
    return p1.lastname < p2.lastname;
  return p1.firstname < p2.firstname;
}

ostream &operator<<(ostream &os, Person p) {
  os << "(firstname:" << p.firstname << ",lastname:" << p.lastname << ")";
  return os;
}

template <typename T>
void print_set(set<T> s) {
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it;
		cout << ",";
  }
  cout << endl;
}

int main() {
  set<Person> s;
  Person p1("Joe", "Biden");
  Person p2("Donald", "Trump");
  s.insert(p1);
  s.insert(p2);
  print_set(s);
}