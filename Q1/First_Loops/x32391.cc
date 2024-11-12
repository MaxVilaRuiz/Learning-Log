#include <iostream>
using namespace std;

int main() {
    int n, d, t, wage, count = 0;
    cin >> d >> n >> t;

    for(int i = 0; i < t; i++) {
        cin >> wage;
        n += wage - d;
        if(n > 0) count++;
    }

    cout << count << endl;
}