#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
class Queue {
  /*****************************************************************/
  private:
  /*****************************************************************/
  struct Item {
    T value;
    Item *next;
  };

  // Points to first element in queue. Its value is NULL if the queue is empty.
  Item *first;
  // Points to last element in queue. Its value is NULL if the queue is empty.
  Item *last;
  int _size;

  Item *copyItems(const Item *pitem) {
    if (pitem == NULL) return NULL;
    Item *pitemcopy = new Item();
    pitemcopy->value = pitem->value;
    pitemcopy->next = copyItems(pitem->next);
    return pitemcopy;
  }

  void deleteItems(Item *pitem) {
    if (pitem == NULL) return;
    deleteItems(pitem->next);
    delete pitem;
  }

  void setLast() {
    if (first == NULL) {
      last = NULL;
      return;
    }
    last = first;
    while (last->next != NULL) last = last->next;
  }

  /*****************************************************************/
  public:
  /*****************************************************************/
  /*
   * Constructors/Destructors/Initializers
   */
  Queue() {
    first = last = NULL;
    _size = 0;
  }

  Queue(const Queue &s) {
    first = copyItems(s.first);
    setLast();
    _size = s._size;
  }

  ~Queue() {
    deleteItems(first);
  }
  
  Queue &operator=(Queue s) {
    if (this == &s) return *this;
    deleteItems(first);
    first = copyItems(s.first);
    setLast();
    _size = s._size;
    return *this;
  }
  
  /*
   * Accessors
   */
  void push(T value) {
		Item* aux = new Item();
    aux->value = value;
    aux->next = last;
    if (last == NULL) {
      last = aux;
      first = aux;
    }
    else {
      last->next = aux;
      last = aux;
    }
    _size++;
  }

  void pop() {
    if (first == NULL) {
      cerr << "Error: can not pop a null queue." << endl;
      exit(1);
    }

    Item *aux = first;
    first = first->next;
    delete aux;
    _size--;

    if (_size == 0) last = NULL;
  }

  T front() {
    if (first == NULL) {
      cerr << "Error: queu is empty" << endl;
      exit(1);
    }
		return first->value;
  }
  
};
