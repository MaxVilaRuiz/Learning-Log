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

  static T suma_i_reis(node_arbre* n, int& count) {
    if (n == NULL) return T(); // suma 0 per subarbre buit
    // Sumes de subarbres
    T sumE = suma_i_reis(n->segE, count);
    T sumD = suma_i_reis(n->segD, count);
    T sumaFills = sumE + sumD;
    if (n->info > sumaFills) count++;
    return n->info + sumaFills;
  }

  // Pre: els valors dels nodes es poden sumar (T ha d’admetre l’operador + i comparació >)
  // Post: El resultat és el nombre de nodes on info > suma dels valors dels seus fills
  int compta_reis_del_turo() const {
    int total = 0;
    suma_i_reis(primer_node, total);
    return total;
  }

};

#endif
