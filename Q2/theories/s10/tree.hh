#include <iostream>

using namespace std;

template<typename T>
class Tree {
  /*****************************************************************/
  private:
  /*****************************************************************/
  struct node_tree {
    T value;
    node_tree* left;
    node_tree* right;
  };

  // Tree's root
  node_tree* root;

  node_tree* copy_nodes(node_tree* u) {
    if (u == NULL) return NULL;
    node_tree* n = new node_tree();
    n->value = u->value;
    n->left = copy_nodes(u->left);
    n->right = copy_nodes(u->right);
    return n;
  }

  void delete_nodes(node_tree *u) {
    if (u == NULL) return;
    delete_nodes(u->left);
    delete_nodes(u->right);
    delete u;
  }

  int count_nodes_helper(node_tree* node) {
    // Base case
    if (node == NULL) return 0;
    // General case
    return count_nodes_helper(node->left)  + 
           count_nodes_helper(node->right) + 1; 
  }

  /*****************************************************************/
  public:
  /*****************************************************************/
  Tree() {
    root = NULL;
  }

  ~Tree() {
    delete_nodes(root);
  }
  
  Tree(Tree& a) {
    root = copy_nodes(a.root);
  }

  bool is_empty() const {
    return root == NULL;
  }
  
  Tree operator=(Tree& a) {
    if (this != &a) {
      node_tree* u = copy_nodes(a.root);
      delete_nodes(root);
      root = u;
    }
    return *this;
  }

  // Apuntes: plantar()
  void create(T value, Tree& tree_left, Tree& tree_right) { 
    node_tree* u = new node_tree();
    u->value = value;
    u->left = tree_left.root;
    u->right = tree_right.root;
    tree_left.root = NULL;
    tree_right.root = NULL;
    delete_nodes(root);
    root = u;
  }

  // Apuntes: fills()
  void explode(Tree& tree_left, Tree& tree_right) {
    node_tree* u = root;
    delete_nodes(tree_left.root);
    delete_nodes(tree_right.root);
    root = NULL;
    tree_left.root = u.left;
    tree_right.root = u.right;
    delete root;
  }

  T get_root() {
    return root->value;
  }

  int count_nodes() {
    // Inmersion!
    return count_nodes_helper(root);
  }
  
};
