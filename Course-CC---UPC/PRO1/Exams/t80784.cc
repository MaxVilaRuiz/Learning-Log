#include <iostream>
using namespace std;

/**
 * @pre  n >= 0
 * @post retorna cert si n és bicolor, fals en cas contrari
 */
bool is_bicolor(int n) {
    int n1 = n % 10;
    n /= 10;

    int n2, compt = 1;
    bool consecutiu = true;
    // Invariant: el número enter 'n' sempre serà major o 
    //            igual a zero (n >= 0).
    while (n > 0) {
        int digit = n % 10;
        if ((digit != n1) and consecutiu) {
            n2 = digit;
            consecutiu = false;
            compt++;
        }
        else if ((digit == n1) and (not consecutiu)) return false;
        else if ((digit != n1) and (digit != n2)) return false;
        
        n /= 10;
    }

    if (compt != 2) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    bool res = is_bicolor(n);
    cout << res << endl;
}