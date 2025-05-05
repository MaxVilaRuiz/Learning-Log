#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
  /*****************************************************************/
  private:
  /*****************************************************************/
  struct Item {
    T value;
    Item* next;
  };

  // Point to the top of the stack (NULL if the stack is empty)
  Item* ptopitem;
	// Size (i.e., num elements in the stack)
  int _size;

  Item* copyItems(const Item *pitem) {
    if (pitem == NULL) return NULL;
    Item* pitemcopy = new Item();
    pitemcopy->value = pitem->value;
    pitemcopy->next = copyItems(pitem->next);
    return pitemcopy;
  }

  void deleteItems(Item* pitem) {
    if (pitem == NULL) return;
    deleteItems(pitem->next);
    delete pitem;
  }

  /*****************************************************************/
  public:
  /*****************************************************************/
  /*
   * Constructors/Destructors/Initializers
   */
  Stack() {
    ptopitem = NULL;
    _size = 0;
  }

  Stack(const Stack& s) {
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
  }

  ~Stack() {
    deleteItems(ptopitem);
  }

  Stack& operator=(Stack& s) {
    if (this == &s) return *this;
    deleteItems(ptopitem);
    ptopitem = copyItems(s.ptopitem);
    _size = s._size;
    return *this;
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

  void push(T value) {
		// 1. Allocate new Item
		Item* ptr = new Item();
		// 2. Set value of the new Item
		ptr->value = value;
		// 3. Link the new item with the old top
		ptr->next = ptopitem; 
		// 4. Point Stack's top to the new Item
		ptopitem = ptr;
		// 5. Increment size
		_size++;
  }

  void pop() {
		// 0. Check empty stack
		if (_size == 0) {
			cerr << "Error: Cannot pop() from an empty stack" << endl;
			exit(1);
		}
		// 1. Save the pointer to the Stack's top
		Item* ptr = ptopitem->next;
		// 2. Delete top (free memory)
		delete ptopitem;
		// 3. Update the top (pointing to the 2nd item)
		ptopitem = ptr;
		// 4. Update size
		_size--;
  }

  T top() {
		// 0. Check empty stack
		if (ptopitem == NULL) {
			cerr << "Error: Cannot top() from an empty stack" << endl;
			exit(-1);
		}
		// 1. Return top
		return ptopitem->value;
  }

};

/*
 * I/O operations
 */
template <typename U>
void readElemsStack(int n, istream& is, Stack<U>& s) {
  if (n == 0) return;
  U value;
  is >> value;
  readElemsStack(n - 1, is, s);
  s.push(value);
}

template <typename U>
void operator>>(istream& is, Stack<U>& s) {
  while (not s.empty()) {
		s.pop();
	}
  int n;
  cin >> n;
  readElemsStack(n, is, s);
}
