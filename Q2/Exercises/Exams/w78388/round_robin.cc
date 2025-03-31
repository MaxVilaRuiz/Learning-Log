#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Simula un algorisme "Round Robin" amb un vector de cues
 *
 * La funció itera circularment (és a dir, considerant l'element n-1 com l'inmediatament anterior al
 * 0) el vector de cues, i va afegint els elements que treu del capdavant de cada cua en una cua
 * resultat.
 *
 * @param  queues  Les cues d'entrada
 * 
 * @returns La cua resultant d'aplicar l'algorisme "Round Robin"
 */
queue<std::string> round_robin(vector<queue<std::string>>& queues) {
    int max_size = 0;
    for (int i = 0; i < queues.size(); i++) {
        if (max_size < queues[i].size()) max_size = queues[i].size();
    }

    queue<string> res; 
    for (int i = 0; i < max_size; i++) {
        for (int j = 0; j < queues.size(); j++) {
            if (i < queues[j].size()) {
                res.push(queues[j].front());
                queues[j].push(queues[j].front());
                queues[j].pop();
            }
        }
    }

    return res;
}