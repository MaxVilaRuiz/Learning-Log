#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Returns (F_n mod m, F_{n+1} mod m)
pair<long long, long long> fib(long long n, long long m) {
    if (n == 0) return {0, 1};

    auto p = fib(n / 2, m);
    long long a = p.first;   // F_k
    long long b = p.second;  // F_{k+1}

    long long c = (a * (2*b + (m - a))) % m;        // F_{2k}
    long long d = (a*a + b*b) % m;                  // F_{2k+1}

    if (n % 2 == 0) return {c, d};
    else return {d, (c + d) % m};
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        cout << fib(n, m).first << "\n";
    }
    return 0;
}