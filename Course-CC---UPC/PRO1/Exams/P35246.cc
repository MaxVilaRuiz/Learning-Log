// Control C502D
#include <iostream>
#include <vector>
using namespace std;

struct Persona {
    string nom;
    int edat;
};

void ordenar(vector<Persona>& v) {  
    bool fi = false;
    int j = v.size() - 1;
    while (not fi and j > 0) {
        if (v[j].edat > v[j - 1].edat)
            swap(v[j], v[j - 1]);
        else if (v[j].edat == v[j - 1].edat and v[j].nom < v[j - 1].nom)
            swap(v[j], v[j - 1]);
        else fi = true;

        j--;
    }
}

int main() {
    int n;
    cin >> n;
    Persona persona;
    vector<Persona> cua;
    for (int i = 0; i < n; i++) {
        cin >> persona.nom >> persona.edat;
        cua.push_back(persona);
        ordenar(cua);
    }

    for (int i = 0; i < cua.size(); i++)
        cout << cua[i].nom << ' ' << cua[i].edat << endl;
}