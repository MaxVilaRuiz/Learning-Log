#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// PRE: v1, v2 are sorted 
//      AND (let V1=v1 and V2=v2 initial copies of v1 and v2, respectively)
// POST: Returns sorted vector with all the elements from V1 and V2
//       Returns sort(v1·v2) 
vector<int> merge(vector<int> v1, vector<int> v2) {
  vector<int> u;
  int n1 = int(v1.size());
  int n2 = int(v2.size());
  int i1 = 0, i2 = 0;
  while (i1 < n1 and i2 < n2) {
    if (v1[i1] <= v2[i2]) u.push_back(v1[i1++]);
    else u.push_back(v2[i2++]);
  }
  while (i1 < n1) u.push_back(v1[i1++]);
  while (i2 < n2) u.push_back(v2[i2++]);
  return u;
}

// PRE: TRUE AND (let V=v initial copy of v)
// POST: Returns a sorted copy of V
//       Returns sort(V) 
//   Decreasing Measure: f(v) = |v|
vector<int> merge_sort(vector<int> v) {
  /*
   * Base Case
   */
  // STEP1: PRE AND |v|<=1 => POST  (v is trivially sorted)
  if (int(v.size()) <= 1) return v;
  /*
   * General Case
   */
  vector<int> v1, v2;
  for (int i = 0; i < int(v.size()); i++) {
    if (i%2 == 0) v1.push_back(v[i]);
    else v2.push_back(v[i]);
  }
  // P := (v1·v2) contains the same elements as v (|v1|+|v2|=|v|)
  //      AND |v1| = |v|+1/2 AND |v2| = |v|/2
  //
  // STEP2: PRE AND |v|>1 AND P => PRE_REC
  vector<int> u1 = merge_sort(v1);
  // HI: u1 = sort(v1)
  vector<int> u2 = merge_sort(v2);
  // HI: u2 = sort(v2)
  //
  // STEP3: PRE AND |v|>1 AND P AND u1=sort(v1) AND u2=sort(v2) => ... => POST
  //
  // PRE AND |v|>1 AND P AND u1=sort(v1) AND u2=sort(v2) => PRE_merge
  vector<int> u = merge(u1,u2);
  // T := PRE AND |v|>1 AND P AND u1=sort(v1) AND u2=sort(v2) AND POST_merge
  //      PRE AND |v|>1 AND P AND u1=sort(v1) AND u2=sort(v2) AND u=sort(v1·v2) 
  // T => POST
  return u;
  // STEP4: PRE AND GENERAL => f(v) > f(v1) AND f(v) > f(v2)
  //        Also f(v) = |v| > 0
}



