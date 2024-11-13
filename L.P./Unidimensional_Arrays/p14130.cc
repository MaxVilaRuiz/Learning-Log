#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 0, n, last;
    cin >> n;

    vector<int> seq(n);
    for (int i = 1; i < n; i++) cin >> seq[i];

    cin >> last;
    for (int i = 1; i < n; i++) 
        if (seq[i] == last) num++;

    cout << num << endl;
}