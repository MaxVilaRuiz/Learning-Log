#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
 private:
	struct Item {
		T value;
		Item *next;
	};

	Item *first, *last;
	int _size;

	void _copy_items(const Item *item, Item *(&first), Item *(&last), int& _size) {
		if (item == nullptr) {
			first = nullptr;
			last = nullptr;
			_size = 0;
			return;
		}
		first = new Item();
		first->value = item->value;
		last = first;
		_size = 1;
		while (item->next != nullptr) {
			last->next = new Item();
			last = last->next;
			item = item->next;
			last->value = item->value;
			_size++;
		}
		last->next = nullptr;
	}

	void _delete_items(Item *item) {
		while (item != nullptr) {
			Item *aux = item;
			item = item->next;
			delete aux;
		}
	}

 public:
	Queue() {
		first = last = nullptr;
		_size = 0;
	}

	Queue(Queue& q) {
		_copy_items(q.first, first, last, _size);
	}

	~Queue() {
		_delete_items(first);
		_size = 0;
	}

	Queue& operator=(const Queue& q) {
		if (this != &q) {
			_delete_items(first);
			_copy_items(q.first, first, last, _size);
		}
		return *this;
	}

	template <typename U>
	friend ostream& operator<<(ostream& os, Queue<U>& q);

	template <typename U>
	friend istream& operator>>(istream& is, Queue<U>& q);

	T front() {
		assert(first != nullptr);
		return first->value;
	}

	void pop() {
		assert(first != nullptr);
		Item *aux = first;
		first = first->next;
		delete aux;
		_size--;
		if (first == nullptr) {
			last = nullptr;
		}
	}

	void push(T value) {
		Item *pitem = new Item();
		pitem->value = value;
		pitem->next = nullptr;
		if (first == nullptr) {
			first = last = pitem;
			_size = 1;
			return;
		}
		last->next = pitem;
		last = pitem;
		_size++;
	}

	int size() {
		return _size;
	}

 public:
	/***********************************************************************
	 * @pre:  Cierto
	 *
	 * @post: Si la cola (p.i.) no contiene el valor 'value', ésta no cambia.
	 *        Si la cola sí lo contiene, se tomará como referencia la primera
	 *        aparición, y se colocarán todos los elementos anteriores a ella
	 *        al final de la cola, en el mismo orden en que estaban.
	 */
	void rotate(T value) {
		Item* paux = first;

		if (paux->value != value) {
			while (paux->next != nullptr && paux->next->value != value) {
				paux = paux->next;
			}
		}

		if (first->value != value && paux->next != nullptr) {
			last->next = first;
			first = paux->next;
			paux->next = nullptr;
			last = paux;
		}
	}

	/***********************************************************************/
};

template <typename U>
ostream& operator<<(ostream& os, Queue<U>& q) {
	os << q._size;
	for (auto *item = q.first; item != nullptr; item = item->next) {
		os << " " << item->value;
	}
	return os;
}

template <typename U>
istream& operator>>(istream& is, Queue<U>& q) {
	int size;
	is >> size;
	if (size == 0) {
		q = Queue<U>();
		return is;
	}
	for (int i = 0; i < size; ++i) {
		U x;
		cin >> x;
		q.push(x);
	}
	return is;
}
