#include <iostream>
#include <list>
using namespace std;

list<int> equals(const list<int>& l1, const list<int>& l2) {
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    list<int> res;
    while (it1 != l1.end() && it2 != l2.end()) {
        if (*it1 == *it2)  {
            res.push_back(*it1);
            it1++;
            it2++;
        } 
        else if (*it1 < *it2) it1++;
        else it2++;
    }

    return res;
}