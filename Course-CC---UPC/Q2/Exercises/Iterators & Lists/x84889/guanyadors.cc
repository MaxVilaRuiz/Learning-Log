#include <string>
#include <vector>
using namespace std;

#include "player.hh"

/*
   Implementa la funció `winners` i envia només aquest fitxer al Jutge.
*/
vector<string> winners(vector<Player>::iterator begin, 
                       vector<Player>::iterator end) {
   int punts = -1;
   string nom = "";
   vector<string> res (0);

   while (begin != end) {
      if (punts < (*begin).score) {
         punts = (*begin).score;
         while (res.size() != 0) {
            res.pop_back();
         } 
         res.push_back((*begin).name);
      }
      else if (punts == (*begin).score) {
         res.push_back((*begin).name);
      }
      begin++;
   }

   return res;
}