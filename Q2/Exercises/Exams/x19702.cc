#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    int i = 0;
    string command;
    while (cin >> command) {
        if (command == "index++;") {
            i++;
        } 
        else if (command == "index--;") {
            i--;
        } 
        else if (command == "v.push_front(") {
            int number;
            cin >> number;
            string ending;
            cin >> ending; // Això consumeix el ");"
            l.push_front(number);
        } 
        else if (command == "v.push_back(") {
            int number;
            cin >> number;
            string ending;
            cin >> ending; // Això consumeix el ");"
            l.push_back(number);
            // for (auto it = l.begin(); it != l.end(); it++) {
            //     cout << *it << ' ';
            // }
            // cout << endl << endl;
        } 
        else if (command == "v.insert(index,") {
            int number;
            cin >> number;
            string ending;
            cin >> ending; // Això consumeix el ");"
            int count = 0;
            auto it = l.begin();
            while (count != i) {
                count++;
                it++;
            }
            l.insert(it, number);
        } 
        else if (command == "cout<<v[index]<<endl;") {
            int count = 0;
            auto it = l.begin();
            while (count != i) {
                count++;
                it++;
            }
            cout << *it << endl;
        }
    }
}