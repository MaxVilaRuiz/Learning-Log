#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v) {
    int low = 0;
    int high = v.size() - 1;
    int res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x) {
            res = mid;
            high = mid;
        }
        else if (v[mid] < x) high = mid - 1;
        else low = mid + 1;
    }

    return res;
}

// int main() {
//     double x;
//     int n;
//     while (cin >> x >> n) {
//         vector<double> vec (n);
//         for (int i = 0; i < n; i++) {
//             cin >> vec[i];
//         }

//         cout << first_occurrence(x, vec) << endl;
//     }
// }

int main() {
    // Test cases:
    vector<vector<double>> test_vectors = {
        {1.1, 2.2, 2.2, 3.3, 5.5},      // Vector with repeated values
        {1.0, 2.0, 3.0, 4.0, 5.0},      // Vector with no duplicate values
        {1.5},                          // Vector with a single element
        {2.2, 3.3, 5.5, 7.7, 9.9},      // Vector with values that do not contain the search element
        {0.0, 0.0, 0.0, 0.0, 0.0},      // Vector with all equal values
        {1.1, 1.2, 1.3, 1.4, 1.5}       // Vector where search value is the last element
    };

    vector<double> test_values = {2.2, 5.0, 1.5, 4.0, 0.0, 1.5};  // Values to search for

    // Expected results:
    vector<int> expected_results = {1, -1, 0, -1, 0, 4}; // Expected indices for each test case

    // Running the tests:
    for (int i = 0; i < test_vectors.size(); i++) {
        int result = first_occurrence(test_values[i], test_vectors[i]);
        cout << "Test case " << i + 1 << ": Searching for " << test_values[i] << " in vector: ";
        for (double val : test_vectors[i]) {
            cout << val << " ";
        }
        cout << endl;
        cout << "Expected result: " << expected_results[i] << endl;
        cout << "Actual result: " << result << endl;
        cout << (result == expected_results[i] ? "Test Passed!" : "Test Failed!") << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}