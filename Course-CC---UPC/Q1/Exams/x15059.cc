#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool sol = true;
    for (int i = 0; i < n; i++) {
        double num1 = 0, num2 = 0;

        cin >> num1;
        if (num1 != -1) {
            while(cin >> num2 and num2 != -1) {
                if (num1 > num2) sol = false;
                num1 = num2;
            }
        }
    }

    if (sol) cout << "Si" << endl;
    else cout << "No" << endl;
}