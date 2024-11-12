#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << "suma dels cubs entre " << a << " i " << b << ": ";

        int sum = 0;
        while (a <= b) {
            sum += (a * a * a);
            a++;
        }

        cout << sum << endl;
    }
}