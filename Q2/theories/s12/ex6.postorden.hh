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

  static T postordre_npos_rec(node_arbre* n, int pos, int& idx, bool& found) {
    if (n == NULL) return T(); // valor per defecte

    // Explora subarbre esquerre
    T res = postordre_npos_rec(n->segE, pos, idx, found);
    if (found) return res;

    // Explora subarbre dret
    res = postordre_npos_rec(n->segD, pos, idx, found);
    if (found) return res;

    // Tracta el node actual
    if (idx == pos) {
      found = true;
      return n->info;
    }
    ++idx;

    return T(); // valor per defecte
  }

  // Pre: 0 <= pos < nombre total de nodes de l'arbre
  // Post: El resultat és el valor del node en posició 'pos' segons un recorregut en postordre
  T postordre_npos(int pos) const {
    int idx = 0;
    bool found = false;
    return postordre_npos_rec(primer_node,pos,idx,found);
  }

};

#endif
