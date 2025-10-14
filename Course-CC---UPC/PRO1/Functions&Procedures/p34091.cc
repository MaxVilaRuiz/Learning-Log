#include <iostream>
using namespace std;

bool is_perfect(int num) {
    if (num < 6) return false;
    else {
        int sum = 1, i;
        for(i = 2; i*i < num; i++) {
            if (num % i == 0) sum += i + (num / i);
        }
        if (i * i == num) sum += i;
        return sum == num;
    }
}

int main() {
    int num;
    cin >> num;
    cout << is_perfect(num);
}