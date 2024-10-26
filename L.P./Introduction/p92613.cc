#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double num;
    cin >> num;

    if (num < 0) {
        bool menor = true;
        while (menor) {
            cin >> num;
            if (num >= 0) {
                menor = false;
            }
        }
    }

    int num_floor = (int)num;
    int num_ceiling = ceil(num);
    int num_round = round(num);

    cout << num_floor << ' ' << num_ceiling << ' ' << num_round << endl;
}