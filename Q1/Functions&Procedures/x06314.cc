//Seqüències similars
#include <iostream>
using namespace std;

void info_sequence (int& sum, int& last) {
    int number = sum;
    while (number != 0){
        cin >> number;
        sum += number;
        if (number != 0)  last = number;
    }
}

int main () {
    int sum_other, last_other = 0;
    int number, last;
    int compt = 1;

    cin >> sum_other;
    info_sequence (sum_other, last_other);

    while (cin >> number) {
        last = 0;
        info_sequence (number, last);
        if (number == sum_other and last == last_other) compt++;
    }
    
    cout << compt << endl;
}