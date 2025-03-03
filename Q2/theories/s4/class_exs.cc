#include <map>
#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

string find_most_frequent_word(list<string>& words) {
    map<string, int> occurrences;
    for (auto it = words.begin(); it != words.end(); it++) {
        occurrences[*it]++;
    }

    pair<string, int> max;
    for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
        if (max.second < (*it).second) max = *it; // 
    }

    return max.first;
}

pair<double, string> analizar_notas(const map<string, int>& notas) {
    if (notas.empty()) return {0, ""};

    double suma = 0;
    string mejor_estudiante;
    int mejor_nota = -1;
    
    for (auto it = notas.begin(); it != notas.end(); it++) {
        suma += (*it).second;
        if (mejor_nota < (*it).second) {
            mejor_estudiante = (*it).first;
            mejor_nota = (*it).second;
        }
    }
    double media = suma / notas.size();

    return {media, mejor_estudiante};
}

set<int> encontrar_duplicados(const vector<int>& numeros) {
    set<int> visitados;
    set<int> duplicados;

    for (int num : numeros) {
        if (visitados.find(numeros[num]) != visitados.end()) {
            duplicados.insert(numeros[num]);
        }
        else visitados.insert(numeros[num]);
    }

    return duplicados;
}