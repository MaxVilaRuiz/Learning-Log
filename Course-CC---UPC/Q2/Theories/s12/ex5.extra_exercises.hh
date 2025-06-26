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

  // Pre: size() > 1
  // Post: El primer element de la llista ha passat a ser l’últim.
  //       No s'ha creat ni esborrat cap node.
  void rotate_left() {
    if (_size <= 1) return;
    // Aïlla el primer node
    Item* first = iteminf.next;
    iteminf.next = first->next;
    first->next->prev = &iteminf;
    // Recol·loca al final
    first->prev = itemsup.prev;
    first->next = &itemsup;
    itemsup.prev->next = first;
    itemsup.prev = first;
  }

  // Pre: La llista està ordenada de menor a major
  // Post: S'ha inserit 'x' mantenint l'ordre de la llista.
  //       S'ha afegit un nou node amb valor 'x' en la posició adequada.
  void insert_sorted(const T& x) {
    Item* curr = iteminf.next;
    while (curr != &itemsup and curr->value < x) {
      curr = curr->next;
    }
    insertItem(curr->prev, x);
  }

  // Pre: k > 0
  // Post: S'ha inserit un element amb valor x cada k posicions, començant per la posició k.
  //       Per exemple, amb llista [A, B, C, D] i k = 2 → [A, B, x, C, D, x]
  //       La mida augmenta depenent de la mida inicial.
  void insert_every_k(const T& x, int k) {
    if (k <= 0) return;
    Item* curr = iteminf.next;
    int index = 1; // Comptem posicions reals (0-based)
    int inserted = 0;
    while (curr != &itemsup) {
      if ((index + inserted) % k == 0) {
        insertItem(curr->prev, x);
        inserted++;
      }
      curr = curr->next;
      index++;
    }
    // Si cal inserir també al final
    if ((_size + inserted) % k == 0) {
      insertItem(itemsup.prev, x);
    }
  }

  // Pre: cert
  // Post: S'han eliminat els elements en posicions parelles (0, 2, 4, ...).
  //       Les posicions es calculen abans d'eliminar cap node.
  void remove_even_positions() {
    Item* curr = iteminf.next;
    int index = 0;
    while (curr != &itemsup) {
      Item* next = curr->next;
      if (index % 2 == 0) {
        // Enllaçat i alliberació manual
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        _size--;
      }
      curr = next;
      index++;
    }
  }
  
};

