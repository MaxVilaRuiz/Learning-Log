#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    int div = 0;
    double num, average = 0;
    while (cin >> num) {
        average += num;
        div++;
    }

    average /= div;
    cout << average << endl;
}