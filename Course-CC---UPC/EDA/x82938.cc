#include <iostream>
#include <vector>
using namespace std;

bool binary_search_asc(const vector<int>& v, int l, int r, int x) {
  if (l > r) return false;
  int m = l + (r - l) / 2;
  if (v[m] < x) return binary_search_asc(v, m+1, r, x);
  if (v[m] > x) return binary_search_asc(v, l, m-1, x);
  return true;
}

bool binary_search_desc(const vector<int>& v, int l, int r, int x) {
  if (l > r) return false;
  int m = l + (r - l) / 2;
  if (v[m] < x) return binary_search_desc(v, l, m-1, x);
  if (v[m] > x) return binary_search_desc(v, m+1, r, x);
  return true;
}

int find_j(const vector<int>& v, int l, int r) {
  if (l == r) return l;
  int m = l + (r - l) / 2;
  if (v[m] < v[m+1]) return find_j(v, m+1, r);
  else return find_j(v, l, m);
}

bool search(int x, const vector<int>& v) {
  int j = find_j(v, 0, v.size()-1);
  return binary_search_asc(v, 0, j, x) || binary_search_desc(v, j, v.size()-1, x);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
