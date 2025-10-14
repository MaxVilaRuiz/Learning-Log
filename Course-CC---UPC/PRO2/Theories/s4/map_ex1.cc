#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>

using namespace std;

string find_most_frequent_word(list<string>& words) {
  map<string, int> occurrences;
  // Add all words to occurrences
  for (auto it = words.begin();
      it != words.end();
      it++) {
    occurrences[*it]++;
  }
  // Find the word that occurs the most
  int max_occ = -1;
  string max_word;
  for (auto it = occurrences.begin();
      it != occurrences.end();
      ++it) {
    if ((*it).second > max_occ) {
      max_occ = (*it).second;
      max_word = (*it).first;
    }
  }
  return max_word;
}

int main() {
  list<string> words;
  words.push_back("Santi");
	words.push_back("Laura");
	words.push_back("Tomas");
  words.push_back("Laura");
	// Count most frequent
  cout << find_most_frequent_word(words) << endl;
}