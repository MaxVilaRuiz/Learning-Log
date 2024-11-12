#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int r;
    while(num >= 2) {
        r = num % 2;
        num /= 2;
        cout << r;
    }
    
    r = num % 2;
    cout << r << endl;
}