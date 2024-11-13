#include <iostream>
using namespace std;

int main() {
    int base, num;
    while(cin >> base >> num) {
        int compt = 1;
        while(num >= base) {
            num /= base;
            compt++;
        }
        cout << compt << endl;
    }
}