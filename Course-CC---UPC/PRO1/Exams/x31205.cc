#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    int mitja = 0;
    while(cin >> n1 >> n2 >> n3) {
        if ((n1 <= n2 and n1 >= n3) or (n1 >= n2 and n1 <= n3)) mitja = n1;
        else if ((n2 <= n1 and n2 >= n3) or (n2 >= n1 and n2 <= n3)) mitja = n2;
        else mitja = n3;
        cout << mitja << endl;
    }
}