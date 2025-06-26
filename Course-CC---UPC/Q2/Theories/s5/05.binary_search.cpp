#include <iostream>
#include <vector>

using namespace std;

// PRE: v is sorted AND
//      v[-1]=-inf AND v[n]=inf
// POST: If (x in v) then returns p st. x = v[p]
//       If (not x in v) then returns -1
//   Recursion Invariant: I := inf < sup AND v[inf] < x <= v[sup]
//   Decreasing Measure: f(sup, inf) = sup - inf
int binary_search_recursive(const vector<int> &v, int x, int inf, int sup) {
    /*
     * Base case
     */
    if (inf + 1 >= sup) {
      // I AND inf+1>=sup AND v[sup-1] < x <= v[sup] => POST
      if (sup < v.size() && v[sup] == x) {
        // v[sup-1] < x <= v[sup] AND sup < n AND v[sup] == x => POST
        return sup;
      } else {
        // v[sup-1] < x <= v[sup] AND (sup >= n OR v[sup] != x) => POST
        return -1;
      }
    }
    /*
     * Recursive case
     */
    int med = (inf + sup) / 2;
    if (v[med] < x) {
      // P AND v[med] < x
      // Recursive Call: inf = med < sup AND v[inf] = v[med] < x <= v[sup] => I
      return binary_search_recursive(v, x, med, sup);
    } else {
      // P AND v[med] >= x
      // Recursive Call: inf < med = sup AND v[inf] < x <= v[med] = v[sup] => I
      return binary_search_recursive(v, x, inf, med);
    }
    // f(sup,inf) > f(sup',inf') since sup - inf > (sup-inf)/2
    // Note that f(sup,inf) > 0
}

// Inmersion
int binary_search(const vector<int> &v, int x) {
    return binary_search_recursive(v, x, -1, v.size());
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9};
    cout << binary_search(v, 5) << endl;  // Output: 2
    cout << binary_search(v, 4) << endl;  // Output: -1
    return 0;
}
