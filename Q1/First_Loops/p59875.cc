#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int contador, limit;
    if (x > y) {
        contador = x;
        limit = y;
    }
    else {
        contador = y;
        limit = x;
    }

    while (contador >= limit) {
        cout << contador << endl;
        contador--;
    }
}