#ifndef ARBRE_HH
#define ARBRE_HH

#include "utils_pro2.hh"

template <class T> 
class Arbre { 

private:     

  struct node_arbre {
    T info;
    node_arbre* segE;
    node_arbre* segD;
  };

  node_arbre* primer_node;

  // especificacion operacions privades

  static node_arbre* copia_node_arbre(node_arbre* m) { 
    /* Pre: cert */
    /* Post: el resultat Es NULL si m Es NULL;
       en cas contrari, el resultat apunta al node arrel 
       d'una jerarquia de nodes que Es una copia de la
       jerarquia de nodes que te el node apuntat per m com a arrel */
    node_arbre* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = copia_node_arbre(m->segE);
      n->segD = copia_node_arbre(m->segD);
    }
    return n;
  }

  static void esborra_node_arbre(node_arbre* m) {  
    /* Pre: cert */
    /* Post no fa res si m Es NULL; en cas contrari,
       allibera espai de tots els nodes de la 
       jerarquia que te el node apuntat per m com a arrel */
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }

public:

  // especificacio operacions publiques

  Arbre() {
    /* Pre: cert */
    /* Post: el p.i. Es un arbre buit */
    primer_node= NULL;
  }

  Arbre(const Arbre& original) {
    /* Pre: cert */
    /* Post: el p.i. Es una copia d'original */
    if (this != &original)     
      primer_node = copia_node_arbre(original.primer_node);
  }

  ~Arbre() {
    esborra_node_arbre(primer_node);
  }

  Arbre& operator=(const Arbre& original) {
    if (this != &original) {
      esborra_node_arbre(primer_node);
      primer_node = copia_node_arbre(original.primer_node);
    }
    return *this;
  }

  void a_buit() {
    /* Pre: cert */
    /* Post: el p.i. Es un arbre buit */
    esborra_node_arbre(primer_node);
    primer_node = NULL;
  }        

  T arrel() const {
    /* Pre: el p.i. no Es buit */
    /* Post: el resultat Es l'arrel del p.i. */
    if (primer_node != NULL) {
      return primer_node->info;    
    } else {
      throw PRO2Excepcio ("Un arbre buit no te arrel");
    }
  }

  bool es_buit() const {
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. Es un arbre buit */
    return (primer_node == NULL);
  }

  // Pre: k >= 0
  // Post: El resultat és el nombre de nodes que hi ha exactament al nivell k (arrel a nivell 0)
  int nombre_nodes_nivell_rec(node_arbre* n, int k) {
    if (n == NULL) return 0;
    if (k == 0) return 1;
    return nombre_nodes_nivell_rec(n->segE, k - 1) + 
          nombre_nodes_nivell_rec(n->segD, k - 1);
  }
  int nombre_nodes_nivell(int k) const {
    return nombre_nodes_nivell_rec(primer_node, k);
  }

  // Pre: cert
  // Post: El resultat és el nombre de vegades que x apareix a l’arbre
  int compta_ocurrències_rec(node_arbre* n, const T& x) {
    if (n == NULL) return 0;
    int match = (n->info == x) ? 1 : 0;
    return match + 
          compta_ocurrències_rec(n->segE, x) + 
          compta_ocurrències_rec(n->segD, x);
  }
  int compta_ocurrències(const T& x) const {
    return compta_ocurrències_rec(primer_node, x);
  }

  // Pre: T admet comparacions < i >
  // Post: El resultat indica si l’arbre compleix la propietat d’arbre binari de cerca (BST)
  bool es_bst(node_arbre* n, const T* min, const T* max) {
    if (n == NULL) return true;
    if ((min != nullptr and n->info <= *min) or 
        (max != nullptr and n->info >= *max)) {
      return false;
    }
    return es_bst(n->segE, min, &n->info) and
           es_bst(n->segD, &n->info, max);
  }
  bool es_arbre_cercador() const {
    return es_bst(primer_node, nullptr, nullptr);
  }

  // Pre: cert
  // Post: El resultat és el nombre de nodes amb exactament un fill no nul
  static int un_sol_fill_rec(node_arbre* n) {
    if (n == NULL) return 0;
    int unfill = (n->segE == NULL) != (n->segD == NULL) ? 1 : 0;
    return unfill +
           un_sol_fill_rec(n->segE) +
           un_sol_fill_rec(n->segD);
  }
  int nombre_nodes_amb_un_sol_fill() const {
    return un_sol_fill_rec(primer_node);
  }

};

#endif
