#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
 * Palindrome ITERATIVE
 */
// PRE: 0<=i<=j+1<=n (being n=|s|)
// POST: Return TRUE <=> For all k in 0..n-1, s[i]=s[n-1-i]  
bool isPalindrom_iter(const string &s) {
  int i = 0;
  int j = int(s.size()) - 1;
  while (i < j) {
    // If characters at i and j don't match, it's not a palindrome.
    if (s[i] != s[j]) return false; 
    i++; // Move towards the center from the left.
    j--; // Move towards the center from the right.
  }
  return true; // If we haven't found any mismatch, it's a palindrome.
}

/*
 * Palindrome RECURSIVE
 */
// PRE: 0<=i<=j+1<=n
// POST: Return TRUE <=> For all k in 0..j-i, s[i+k]=s[j-k] 
bool isPalindrom_rec(int i,int j,const string &s) {
  if (j <= i) return true;
  if (s[i] != s[j]) return false;
  // HI: Return TRUE <=> For all k in 0..j-i, s[i+1 + k]=s[j-1 - k] 
  return isPalindrom_rec(i+1,j-1,s);
}
// PRE: TRUE
// POST: Return TRUE <=> For all k in 0..n-1, s[i]=s[n-1-i] (n=|s|)
bool isPalindrom(const string &s) {
  return isPalindrom_rec(0,int(s.size())-1,s);
}


