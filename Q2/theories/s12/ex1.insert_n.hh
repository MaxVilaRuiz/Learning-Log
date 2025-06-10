#include <iostream>

using namespace std;

template <typename T> class List {
private:
  
  // Items:
  
  class Item {
  public:
    T value;
    Item *next;
    Item *prev;
  };

  // Data:
  
  int _size;
  Item iteminf,itemsup;

  // Mètodes auxiliars

  void insertItem(Item *pitemprev, Item *pitem)
  /* Pre: pitemprev apunta a un element del p.i.
     pitemprev != pitem, 
     pitemprev.next = P, 
     pitem != nullptr,
     pitem apunta a un element singular */
  /* Post: inserta al p.i. el node apuntat per pitem entre el node apuntat
     per pitemprev i P, augmenta _size en 1 */  
  {
    pitem->next = pitemprev->next;
    pitem->next->prev = pitem;
    pitem->prev = pitemprev;
    pitemprev->next = pitem;
    _size++;
  }
  
  void insertItem(Item *pitemprev, const T &value) 
  /* Pre: pitemprev apunta un element del p.i.
     pitemprev.next = P */
  /* Post: inserta al p.i. un node amb valor value entre el node apuntat
     per pitemprev i P, augmenta _size en 1 */
  {
    Item *pitem = new Item;
    pitem->value = value;
    insertItem(pitemprev, pitem);
  }

  void extractItem(Item *pitem)
  /* Pre: pitem != & iteminf, pitem != &itemsup
     pitem apunta a un element del p.i. */
  /* Post: enllaça doblement el node anterior a pitem amb el posterior
     a pitem, disminueix en 1 _size */
  {
    pitem->next->prev = pitem->prev;
    pitem->prev->next = pitem->next;
    _size--;
  }

  void removeItem(Item *pitem) 
  /* Pre: pitem != & iteminf, pitem != &itemsup */
  /* Post: enllaça doblement el node anterior a pitem amb el posterior
     a pitem, s'allibera la memòria del node apuntat per pitem */
  {
    extractItem(pitem);
    delete pitem;
  }
    
  void removeItems() {
  /* Pre: _size = S */
  /* Post: s'ha alliberat la memòria dels S nodes entre iteminf i itemsup,
     iteminf.next = &itemsup, itemsup.prev = &iteminf, _size = 0*/
    while (_size > 0)
      removeItem(iteminf.next);
  }
  
  void copyItems(List & l) {
  /* Pre: cert*/
  /* Post: copia els elements de la llista l al p.i. */
    for (Item *pitem = l.itemsup.prev; pitem != &l.iteminf; pitem = pitem->prev)
      insertItem(&iteminf, pitem->value); 
  }
  
  
public:

  // Constructors/Destructors:
  
  List() 
  /* Pre: cert*/
  /* Post: el resultat és una llista sense elements */
  {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
  }

  List(List &l) 
  /* Pre: cert */
  /* Post: El resultat és una còpia d’l */
  {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
    copyItems(l);
  }

  ~List() 
  // Destructora: Esborra automàticament els objectes locals en
  // sortir d’un àmbit de visibilitat
  {
    removeItems();
  }

  // Assignment:
  
  List &operator=(const List &l) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d’l i qualsevol
     contingut anterior del p.i. ha estat esborrat
    (excepte si el p.i. i l ja eren el mateix objecte) */
  {
    if (this != &l) {
      removeItems();
      copyItems(l);
    }
    return *this;
  }

  // Standard operations:
  
  int size() const
  /* Pre: cert */
  /* Post: el resultat és el nombre de nodes del p.i
     (els nodes iteminf i itemsup no es conten) */
  {
    return _size;
  }

  bool empty() const
  /* Pre: cert */
  /* Post: el resultat és si el p.i té nodes o no
     (els nodes iteminf i itemsup no conten) */
  {
    return _size == 0;
  }

  void push_back(const T &value) 
  /* Pre: cert */
  /* Post: s'inserta un node amb valor value al final del p.i. */
  {
    insertItem(itemsup.prev, value);
  }
  
  void push_front(const T &value) 
  /* Pre: cert */
  /* Post: s'inserta un node amb valor value al principi del p.i. */
  {
    insertItem(&iteminf, value);
  }

  void pop_back() 
  /* Pre: el p.i. no és buit */
  /* Post: s'esborra el primer node del p.i. */
  {
    if (_size == 0) {
      cerr << "Error: pop_back on empty list" << endl;
      exit(1);
    }
    removeItem(itemsup.prev);
  }

  void pop_front()
  /* Pre: el p.i. no és buit */
  /* Post: s'esborra el darrer node del p.i. */
  {
    if (_size == 0) {
      cerr << "Error: pop_front on empty list" << endl;
      exit(1);
    }
    removeItem(iteminf.next);
  }

  // Pre: 0 <= n <= size()
  // Post: S'ha inserit un nou element amb valor 'value' a la posició 'n' (començant en 0).
  //       Els elements que abans estaven en posicions >= n s'han desplaçat una posició cap endarrere.
  //       Si n == size(), l'element s'insereix al final de la llista.
  //       No es modifica cap element existent, només s'afegeix un nou node.
  //       En cas contrari, el programa finalitza amb error.
  void insert_at(int n, const T& value) {
    if (n < 0 or n > _size) {
      cerr << "Error: insert_at amb posició fora de rang" << endl;
      exit(1);
    }
    Item* current = &iteminf;
    for (int i = 0; i < n; ++i) {
      current = current->next;
    }
    insertItem(current, value);
  }
  
};

