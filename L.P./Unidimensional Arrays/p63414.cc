#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(1001, 0);
    int n; 
    cin >> n;
    
    while(n > 0) {
        n--;
        int num;
        cin >> num;
        ++v[num -1000000000];
    }

    while(n < 1001) {
        if (v[n] > 0) cout << n + 1000000000 << " : " << v[n] << endl;
        n++;
    }
}