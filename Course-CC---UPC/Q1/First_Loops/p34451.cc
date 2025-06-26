#include <iostream>
using namespace std;

int main() {
    int multiple, num, compt = 0;
    cin >> multiple;

    while (cin >> num) {
        if (num % multiple == 0) compt++;
    }

    cout << compt << endl;
}