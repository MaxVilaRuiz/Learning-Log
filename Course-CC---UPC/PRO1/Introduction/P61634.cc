#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    if (year < 1800 || year > 9999) {
        return 1;
    }

    bool isLeapYear = false;
    if (year % 400 == 0) {
        isLeapYear = true;
    } 
    else if (year % 100 == 0) {
        isLeapYear = false;
    } 
    else if (year % 4 == 0) {
        isLeapYear = true;
    } 

    if (isLeapYear) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
