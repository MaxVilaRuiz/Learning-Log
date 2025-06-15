#include <iostream>

using namespace std;

/**
 * @brief Doubly linked list implementation.
 * @tparam T Type of elements stored in the list.
 */
template <typename T> class List {
private:

  /**
   * @brief Internal node class for list elements.
   */
  class Item {
  public:
    T value;       ///< Value stored in the node.
    Item *next;    ///< Pointer to the next node.
    Item *prev;    ///< Pointer to the previous node.
  };

  int _size;        ///< Number of elements in the list.
  Item iteminf;     ///< Sentinel node at the beginning.
  Item itemsup;     ///< Sentinel node at the end.

  /**
   * @brief Inserts a node into the list between two existing nodes.
   * @param pitemprev Pointer to the node after which the new node will be inserted.
   * @param pitem Pointer to the node to insert.
   */
  void insertItem(Item *pitemprev, Item *pitem) {
    pitem->next = pitemprev->next;
    pitem->next->prev = pitem;
    pitem->prev = pitemprev;
    pitemprev->next = pitem;
    _size++;
  }

  /**
   * @brief Creates and inserts a new node with a given value.
   * @param pitemprev Pointer to the node after which the new value is inserted.
   * @param value Value to insert.
   */
  void insertItem(Item *pitemprev, const T &value) {
    Item *pitem = new Item;
    pitem->value = value;
    insertItem(pitemprev, pitem);
  }

  /**
   * @brief Disconnects a node from the list.
   * @param pitem Pointer to the node to disconnect.
   */
  void extractItem(Item *pitem) {
    pitem->next->prev = pitem->prev;
    pitem->prev->next = pitem->next;
    _size--;
  }

  /**
   * @brief Removes and deletes a node from the list.
   * @param pitem Pointer to the node to delete.
   */
  void removeItem(Item *pitem) {
    extractItem(pitem);
    delete pitem;
  }

  /**
   * @brief Clears the list, removing and deleting all nodes.
   */
  void removeItems() {
    while (_size > 0)
      removeItem(iteminf.next);
  }

  /**
   * @brief Copies all nodes from another list.
   * @param l List to copy from.
   */
  void copyItems(List &l) {
    for (Item *pitem = l.itemsup.prev; pitem != &l.iteminf; pitem = pitem->prev)
      insertItem(&iteminf, pitem->value); 
  }

public:
  /**
   * @brief Constructs an empty list.
   */
  List() {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
  }

  /**
   * @brief Copy constructor.
   * @param l List to copy.
   */
  List(List &l) {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
    copyItems(l);
  }

  /**
   * @brief Destructor. Frees all memory used by the list.
   */
  ~List() {
    removeItems();
  }

  /**
   * @brief Assignment operator.
   * @param l List to assign from.
   * @return Reference to this list.
   */
  List &operator=(const List &l) {
    if (this != &l) {
      removeItems();
      copyItems(const_cast<List&>(l));
    }
    return *this;
  }

  /**
   * @brief Returns the number of elements in the list.
   * @return Size of the list.
   */
  int size() const {
    return _size;
  }

  /**
   * @brief Checks if the list is empty.
   * @return True if empty, false otherwise.
   */
  bool empty() const {
    return _size == 0;
  }

  /**
   * @brief Appends an element to the end of the list.
   * @param value Value to append.
   */
  void push_back(const T &value) {
    insertItem(itemsup.prev, value);
  }

  /**
   * @brief Prepends an element to the beginning of the list.
   * @param value Value to prepend.
   */
  void push_front(const T &value) {
    insertItem(&iteminf, value);
  }

  /**
   * @brief Removes the last element of the list.
   */
  void pop_back() {
    if (_size == 0) {
      cerr << "Error: pop_back on empty list" << endl;
      exit(1);
    }
    removeItem(itemsup.prev);
  }

  /**
   * @brief Removes the first element of the list.
   */
  void pop_front() {
    if (_size == 0) {
      cerr << "Error: pop_front on empty list" << endl;
      exit(1);
    }
    removeItem(iteminf.next);
  }

  template <typename U> friend istream &operator>>(istream &is, List<U> &l);
  template <typename U> friend ostream &operator<<(ostream &os, List<U> &l);

  // Mutable iterator class declaration
  class iterator {
    friend class List;
  private:
    List *plist;
    Item *pitem;
  public:

    /**
     * @brief Pre-increment operator.
     */
    iterator operator++() {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: ++iterator at the end of list" << endl;
        exit(1);
      }
      pitem = pitem->next;
      return *this;
    }

    /**
     * @brief Post-increment operator.
     */
    iterator operator++(int) {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: iterator++ at the end of list" << endl;
        exit(1);
      }
      iterator aux = *this;
      pitem = pitem->next;
      return aux;
    }

    /**
     * @brief Pre-decrement operator.
     */
    iterator operator--() {
      if (pitem == plist->iteminf.next) {
        cerr << "Error: --iterator at the beginning of list" << endl;
        exit(1);
      }
      pitem = pitem->prev;
      return *this;
    }

    /**
     * @brief Post-decrement operator.
     */
    iterator operator--(int) {
      if (pitem == plist->iteminf.next) {
        cerr << "Error: iterator-- at the beginning of list" << endl;
        exit(1);
      }
      iterator aux = *this;
      pitem = pitem->prev;
      return aux;
    }

    /**
     * @brief Dereference operator.
     */
    T& operator*() {
      if (pitem == &(plist->itemsup)) {
        cerr << "Error: *iterator at the end of list" << endl;
        exit(1);
      }
      return pitem->value;
    }

    /**
     * @brief Equality operator.
     */
    bool operator==(const iterator &it) const {
      return plist == it.plist && pitem == it.pitem;
    }

    /**
     * @brief Inequality operator.
     */
    bool operator!=(const iterator &it) const {
      return !(*this == it);
    }
  };

  /**
   * @brief Returns iterator to the beginning of the list.
   */
  iterator begin() {
    iterator it;
    it.plist = this;
    it.pitem = iteminf.next;
    return it;
  }

  /**
   * @brief Returns iterator to the end of the list.
   */
  iterator end() {
    iterator it;
    it.plist = this;
    it.pitem = &itemsup;
    return it;
  }

  /**
   * @brief Inserts a value before the position pointed by iterator.
   */
  iterator insert(iterator it, const T & value) {
    if (it.plist != this) {
      cout << "Error: insert with an iterator not on this list" << endl;
      exit(1);
    }
    iterator res = it;
    insertItem(res.pitem->prev, value);
    res.pitem = res.pitem->prev;
    return res;
  }

  /**
   * @brief Erases the element at the iterator position.
   */
  iterator erase(iterator it) {
    if (it.plist != this) {
      cout << "Error: erase with an iterator not on this list" << endl;
      exit(1);
    }
    if (it.pitem == &itemsup) {
      cout << "Error: erase with an iterator pointing to the end of the list" << endl;
      exit(1);
    }
    iterator res = it;
    res.pitem = res.pitem->next;
    removeItem(res.pitem->prev);
    return res;
  }

  // Const iterator class follows the same structure...

  // You can tell me if you want me to continue with const_iterator and stream functions
};