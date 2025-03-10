#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
 * Palindrome RECURSIVE
 */
// PRE: 0<=i<=j+1<=n (being n=|s|)
// POST: Return TRUE <=> For all k in 0..j-i, s[i+k]=s[j-k] 
//   Decreasing Measure: f(j,i) = j+1-i  (a.k.a. Termination argument)
bool isPalindrome_rec(int i,int j,const string &s) {
  /*
   * Base Cases
   */
  // STEP1: PRE AND (j<=i) => POST
  if (j <= i) return true;
  // STEP1: PRE AND (s[i]!=s[j]) => POST
  if (s[i] != s[j]) return false;
  /*
   * General Case
   */
  // STEP2: PRE AND i<j AND s[i]=s[j] => PRE_REC
  return isPalindrome_rec(i+1,j-1,s);
  // HI: Return TRUE <=> For all k in 0..(j-1)-(i+1), s[i+1+k]=s[j-1-k] 
  //
  // STEP3:
  //  PRE AND i<j AND s[i]=s[j] AND POST_REC => POST 
  //  PRE AND i<j AND s[i]=s[j] AND For all k in 0..(j-1)-(i+1), s[i+1+k]=s[j-1-k] => POST
  //
  // STEP4: 
  //  PRE AND GENERAL => f(j,i) > f(j',i'), where i’=i+1, j’=j-1
  //  Also, f(j,i) = j+1-i > 0
}
// PRE: TRUE
// POST: Return TRUE <=> For all k in 0..n-1, s[i]=s[n-1-i] (being n=|s|)
bool isPalindrome(const string &s) {
  return isPalindrome_rec(0,int(s.size())-1,s);
}