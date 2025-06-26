#include <iostream>
using namespace std;

void cross(int n, char c) {
    int comptador = n / 2;
    for(int i = 0; i < n; i++) {
        if (i != comptador) {
            for(int j = 0; j < comptador; j++)
                cout << ' ';
            cout << c << endl;
        }
        else {
            for(int e = 0; e < n; e++) cout << c;
            cout << endl;
        }
    }
}

int main() {
    int n;
    char c;
    cin >> n >> c;
    cross(n, c);
}