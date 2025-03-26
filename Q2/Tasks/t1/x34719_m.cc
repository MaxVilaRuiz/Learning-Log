#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Log {
    string ip;
    string path;
    int time;
};

struct Map_content {
    int count;
    int last;
    vector<string> paths;
};


// void merge(vector<string>& v, int left, int mid, int right) {
//     int n = right - left + 1;
//     vector<string> aux(n);
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     while (i <= mid && j <= right) {
//         if (v[i] <= v[j]) {
//             aux[k] = v[i];
//             i++;
//         }
//         else {
//             aux[k] = v[j];
//             j++;
//         }
//         k++;
//     }

//     while (i <= mid) {
//         aux[k] = v[i];
//         i++; k++;
//     }
//     while (j <= right) {
//         aux[k] = v[j];
//         j++; k++;
//     }

//     for (k = 0; k < n; k++) {
//         v[left + k] = aux[k];
//     }
// }

// void merge_sort(vector<string>& v, int left, int right) {
//     if (left < right) {
//         int mid = (left + right) / 2;
//         merge_sort(v, left, mid);
//         merge_sort(v, mid+1, right);
//         merge(v, left, mid, right);
//     }
// }

// // Pre:
// // Post:
// bool contains_v(const vector<string>& v, string s) {
//     int left = 0, right = v.size() - 1;
//     while (left <= right) {
//         int i = (left + right) / 2;
//         if (s < v[i]) right = i - 1;
//         else if (s > v[i]) left = i + 1;
//         else return true;
//     }
//     return false;
// }

// // Pre:
// // Post:
// void insert_v(vector<string>& v, string s) {
//     v.push_back(s);
//     int i = v.size() - 1;
//     while (0 < i && s < v[i-1]) {
//         v[i] = v[i-1];
//         i--;
//     }
//     v[i] = s;
// }

// // Pre:
// // Post:
// auto find_map(map<string, Map_content >& M, string s) {
//     auto it = M.begin();
//     while (it != M.end()) {
//         if (s == (*it).first) return it;
//         else it++;
//     }
//     return it;
// }

int main() { 
    map<string, Map_content > M;   
    vector<string> bots;
    Log access;
    while (cin >> access.ip >> access.path >> access.time) {
        auto it = M.find(access.ip);

        if (it != M.end()) {
            if (access.time - (*it).second.last < 100) {
                (*it).second.count++;
                if ((*it).second.count == 20) bots.push_back(access.ip);
            }
            else {
                if ((*it).second.count < 20) (*it).second.count = 1;
            }

            auto i = find((*it).second.paths.begin(), (*it).second.paths.end(), access.path);
            if (i == (*it).second.paths.end()) {
                (*it).second.paths.push_back(access.path);
            }

            (*it).second.last = access.time;
        }
        else {
            M[access.ip] = {1, access.time, {access.path}};
        }
    }

    // Output
    if (0 < bots.size()) {
        sort(bots.begin(), bots.end());
        for (int i = 0; i < bots.size(); i++) {
            cout << bots[i];
            sort(M[bots[i]].paths.begin(), M[bots[i]].paths.end());
            for (int j = 0; j < M[bots[i]].paths.size(); j++) {
                cout << ' ' << M[bots[i]].paths[j];
            }
            cout << endl;
        }
    }
    else cout << "No bots" << endl;
}