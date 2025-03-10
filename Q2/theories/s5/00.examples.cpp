#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// PRE:  n >= 0
// POST: Devuelve n!
int factorial(int n) {
  return n == 0 ? 1 : n * factorial(n - 1);
}

// PRE: y >= 0
// POST: Devuelve x^y
int power(int x, int y) {
  return y == 0 ? 1 : x * power(x, y - 1);
}
int power_fast(int x, int y) { // Mejorada
  if (y == 0) {
    return 1;
  } else {
      const int r = power_fast(x, y/2);
    return (y % 2 == 1 ? x : 1) * r * r;
  }
}

// PRE: n >= 0
// POST: Devuelve la suma de los dígitos de n
int sum_of_digits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n % 10 + sum_of_digits(n / 10);
  } 
}

// PRE: True
// POST: Devuelve el reverso de s
string reverse_string(string s) {
  if (s.size() == 0) {
    return "";
  } else {
    return reverse_string(s.substr(1)) + s[0];
  }
}

// PRE: True
// POST: Devuelve si s es palindromo
bool is_palindrome(string s) {
  if (s.size() <= 1) {
    return true;
  } else {
    return s[0] == s[s.size() - 1] && 
        is_palindrome(s.substr(1, s.size() - 2));
  }
}

// PRE: n >= 0
// POST: Imprime s por pantalla n veces
void print_times(string s, int n) {
  if (n == 0) {
    cout << endl;
  } else {
    cout << s << ' ';
    print_times(s, n - 1);
  }
}

