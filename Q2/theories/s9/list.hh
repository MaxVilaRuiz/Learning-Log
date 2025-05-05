#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
class List {
  /*****************************************************************/
  private:
  /*****************************************************************/
  struct Item {
    T value;
    Item *next;
    Item *prev;
  };

  Item iteminf;
	Item itemsup;
  int _size;

  void insertItem(Item* pitemprev, Item* pitem) {
    pitemprev->next->prev = pitem;
    pitem->next = pitemprev->next;
		pitemprev->next = pitem;
    pitem->prev = pitemprev;
  }

  void insertValue(Item *pitemprev, T value) {
    Item* pitem = new Item();
    pitem -> value = value;
    insertItem(pitemprev, pitem);
  }

  void removeItem(Item *pitem) {
    pitem->next->prev = pitem->prev;
    pitem->prev->next = pitem->next;
    _size--;
  }

  void deleteItem(Item *pitem) {
    removeItem(pitem);
    delete pitem;
  }
  /*****************************************************************/
  public:
  /*****************************************************************/
  /*
   * Constructors/Destructors/Initializers
   */
  List() {
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
    _size = 0;
  }

  /*
   * Accessors
   */
  int size() {
    return _size;
  }

  bool empty() {
    return _size == 0;
  }

  void push_front(T value) {
    insertValue(&iteminf, value);
  }

  void push_back(T value) {
    insertValue(itemsup.prev , value);
  }

  void pop_front() {
    if (_size == 0) {
      cerr << "Error: 'pop_front' on empty list" << endl;
      exit(1);
    }
    deleteItem(iteminf.next);
  }

  void pop_back() { 
    if (_size == 0) {
      cerr << "Error: 'pop_back' on empty list" << endl;
      exit(1);
    }
    deleteItem(itemsup.prev);
  }

  /*
   * List Iterator
   */
  class iterator {
    friend List;
  private:
    Item* pitem;
    List* plist;
  public:
    iterator operator++() {
      if (pitem == &(plist->itemsup)) {
				cerr << "Error: operator '++' on iterator at end of list" << endl;
				exit(1);
      }
      pitem = pitem->next;
      return *this;
    }

    iterator operator++(int) {
      iterator it = *this;
      operator++();
      return it;
    }

    iterator operator--() {
      if (pitem == plist->iteminf.next) {
				cerr << "Error: operator '--' on iterator at begin of list" << endl;
				exit(1);
      }
      pitem = pitem->prev;
      return *this;
    }

    iterator operator--(int) {
      iterator it = *this;
      operator--();
      return it;
    }
    
    T operator*() {
      return pitem->value;
    }
  };

  iterator begin() {
    iterator it;
    it.pitem = iteminf.next;
    it.plist = this;
    return it;
  }

  iterator end() {
    iterator it;
    it.pitem = &itemsup;
    it.plist = this;
    return it;
  }

  void insert(iterator it, T value) {
    insertValue(it.pitem->prev, value);
  }

  iterator erase(iterator it) {
    iterator itaux;
    itaux.pitem = it.pitem->next;
    itaux.plist = it.plist;
    deleteItem(it.pitem);
    return itaux;
  }
  
  template<typename U> friend
  ostream &operator<<(ostream &os, List<U> &l);
};

/*
 * I/O operations
 */
template<typename U>
ostream &operator<<(ostream &os, List<U> &l) {
  bool writespace = false;
  for (typename List<U>::Item *pitem = l.iteminf.next; 
       pitem != &l.itemsup; 
       pitem = pitem->next) {
    if (writespace) os << " ";
    writespace = true;
    os << pitem->value;
  }
  return os;
}



