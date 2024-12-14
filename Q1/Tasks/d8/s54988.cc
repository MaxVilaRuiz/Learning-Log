#include <iostream>
#include <vector>
using namespace std;

struct Fruit {
   string name;
   int amount;
};

// Pre: L'entrada consisteix en un vector, un string (element que es vol trobar)
//      i dos enters que representen cada extrem (dret i esquerra) del vector.
// Post: Si s'ha trobat l'element de l'entrada al vector, la funció retorna la 
//       posició en la qual s'ha trobat; altrament, retorna -1.
int bin_search(const vector<Fruit>& v, string fruit, int left, int right) {
    while (left <= right) {
        int i = (left + right) / 2;
        if (fruit < v[i].name) right = i - 1;
        else if (fruit > v[i].name) left = i + 1;
        else return i; 
    }

    return -1;
}

// Pre: L'entrada consisteix en un vector i un variable de tipus "Fruit".
// Post: La funció implementa el contingut de la variable "Fruit" al vector: si 
//       el tipus de "Fruit" ja existent al vector, se suma de la que ja existeix; 
//       altrament, s'implementa en la posició que li pertoca (de manera ordenada).
void add_fruit(vector<Fruit>& fruits, const Fruit& fruit) {
    if (fruits.size() == 0)
        fruits.push_back(fruit);
    else {
        int pos = bin_search(fruits, fruit.name, 0, fruits.size() - 1);

        if (pos != -1)
            fruits[pos].amount += fruit.amount;
        else {
            fruits.push_back(fruit);
            int i = fruits.size() - 1;
            while ((i > 0) and (fruits[i].name < fruits[i - 1].name)) {
                swap(fruits[i], fruits[i - 1]);
                i--;
            }

        }
    }
}

// Pre: L'entrada consisteix en una seqüència sense sentinella de variables de tipus "Fruita".
// Post: Es mostra per pantalla la llista d'elements que s'han introduït de manera ordenada. 
int main() {
    vector<Fruit> fruits;
    Fruit f;
    while (cin >> f.name >> f.amount)
        add_fruit(fruits, f);

    for (int i = 0; i < fruits.size(); i++)
        cout << fruits[i].name << ' ' << fruits[i].amount << endl;
    
    return 0;
}