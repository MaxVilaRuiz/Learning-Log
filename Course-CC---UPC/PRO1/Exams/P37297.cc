#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num < 100) {
        return 1;
    }

    string num_string = to_string(num);
    int digit1 = num_string[num_string.length() - 3] - '0';
    int digit2 = num_string[num_string.length() - 2] - '0';
    int digit3 = num_string[num_string.length() - 1] - '0';

    int operation = digit1 + digit2 + digit3;
    cout << operation << endl;
}