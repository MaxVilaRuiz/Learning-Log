#include <iostream>
#include <vector>
using namespace std;

void merge(vector<string>& v, int left, int mid, int right) {
    int n = right - left + 1;
    vector<string> aux(n);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid and j <= right) {
        if (v[i] <= v[j]) {aux[k] = v[i]; i++;}
        else {aux[k] = v[j]; j++;}
        k++;
    }

    while (i <= mid) {aux[k] = v[i]; k++; i++;}
    while (j <= right) {aux[k] = v[j]; k++; j++;}

    for (k = 0; k < n; k++) v[left + k] = aux[k];
}

void merge_sort(vector<string>& v, int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;
        merge_sort(v, left, m);
        merge_sort(v, m + 1, right);
        merge(v, left, m, right);
    }
}

int max_pos(const vector<string>& v) {
    int max = 1, current = 1, pos = 0;
    string last = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (last != v[i]) {
            current = 1;
            last = v[i];
        }
        else current++;

        if (max < current) {
            max = current;
            pos = i;
        }
        else if (max == current) {
            if (v[pos] < v[i]) {
                max = current;
                pos = i;
            }
        }
    }
    return pos;
}

int main() {
    int n;
    while (cin >> n and n != 0) {
        vector<string> input(n);
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }

        merge_sort(input, 0, n - 1);

        cout << input[max_pos(input)] << endl;
    }
}