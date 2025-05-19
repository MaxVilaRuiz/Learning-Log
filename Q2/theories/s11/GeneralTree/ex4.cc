#ifndef ARBREN_HH
#define ARBREN_HH

#include "utils_pro2.hh"
#include <vector>

template <class T> class ArbreNari { 
  private:
  // especificaci� operacions privades

  struct node_arbreNari {
    T info;
    vector<node_arbreNari*> seg;
  };

  int N;
  node_arbreNari* primer_node;
	
  static node_arbreNari* copia_node_arbreNari(node_arbreNari* m) { 
  /* Pre: cert */
  /* Post: el resultat �s NULL si m �s NULL; en cas contrari, el resultat apunta
          al node arrel d'una jerarquia de nodes que �s una c�pia de la 
          jerarquia de nodes que t� el node apuntat per m com a arrel */
    node_arbreNari* n;
    if (m == NULL) n = NULL;
    else {
      n = new node_arbreNari;
      n->info = m->info;
      int ari = m->seg.size();
      n->seg = vector<node_arbreNari*>(ari);
      for (int i = 0; i < ari; ++i) 
        n->seg[i] = copia_node_arbreNari(m->seg[i]);
    }
    return n;
  }

  static void esborra_node_arbreNari(node_arbreNari* m) {  
    /* Pre: cert */
    /* Post no fa res si m �s NULL; en cas contrari, allibera espai de tots els nodes
            de la jerarquia que t� el node apuntat per m com a arrel */
    if (m != NULL) {
      int ari = m->seg.size();
      for (int i = 0; i < ari; ++i) 
        esborra_node_arbreNari(m->seg[i]);
      delete m;
    }
  }

  public:
  // especificaci� operacions p�bliques

  /* Pre: cert */
  /* Post: el p.i. �s un arbre buit d'aritat n */
  ArbreNari(int n) {
    N = n;
    primer_node= NULL;
  }

  /* Pre: cert */
  /* Post: el p.i. �s un arbre amb arrel x i n fills buits */
  ArbreNari(const T &x, int n) {
    N = n;
    primer_node= new node_arbreNari;
    primer_node->info = x;
    primer_node->seg = vector<node_arbreNari*>(N);
    for (int i=0; i<N; ++i) 
      primer_node->seg[i] = NULL;
  }

  /* Pre: cert */
  /* Post: el p.i. �s una c�pia d'original */
  ArbreNari(const ArbreNari& original) {
    N = original.N;
    primer_node = copia_node_arbreNari(original.primer_node);
  }

  // Destructora: Esborra autom�ticament els objectes locals en
  // sortir d'un �mbit de visibilitat
  ~ArbreNari() {
    esborra_node_arbreNari(primer_node);
  }

  /* Pre: cert */
  /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
      contingut anterior del p.i. ha estat esborrat 
      (excepte si el p.i. i original ja eren el mateix objecte) */
  ArbreNari& operator=(const ArbreNari& original) {
    if (this != &original) {
      esborra_node_arbreNari(primer_node);
      N = original.N;
      primer_node = copia_node_arbreNari(original.primer_node);
    }
    return *this;
  }

  /* Pre: cert */
  /* Post: el p.i. �s un arbre buit */
  void a_buit() {
    esborra_node_arbreNari(primer_node);
    primer_node= NULL;
  }        

  /* Pre: cert */
  /* Post: el resultat indica si el p.i. �s un arbre buit */
  bool es_buit() const {
    return (primer_node == NULL);
  }

  /* Pre: cert */
  /* Post: el resultat �s l'aritat del p.i. */
  int aritat() const {
    return N;
  }

  /* Pre: el p.i. no �s buit */
  /* Post: el resultat �s l'arrel del p.i. */
  T arrel() const {
    if (primer_node != NULL)   return primer_node->info;
    else throw PRO2Excepcio("El p.i. d'arrel no pot ser buit a la crida");
  }

  /*
   * Ejercicio 4: Búsqueda y nivel
   *   Devuelve la profundidad (nivel) del nodo que contiene x. 
   *   La raíz está a nivel 0. Si no está, devuelve -1.
   */
  int nivell_de_node(node_arbreNari* n, const T& x, int nivell) const {
    if (n == NULL) return -1;
    if (n->info == x) return nivell;
    for (node_arbreNari* f : n->seg) {
      int subnivell = nivell_de_node(f, x, nivell + 1);
      if (subnivell != -1) return subnivell;
    }
    return -1;
  }

  int nivell_de(const T& x) const {
    return nivell_de_node(primer_node, x, 0);
  }

};

#endif
