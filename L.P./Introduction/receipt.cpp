#include <iostream>
using namespace std;

int main() {
    int e, c;
    cin >> e >> c;

    int b_500 = e / 500;
    int b_200 = (e % 500) / 200;
    int b_100 = ((e % 500) % 200) / 100; 
    int b_50 = (((e % 500) % 200) % 100) / 50;
    int b_20 = ((((e % 500) % 200) % 100) % 50) / 20;
    int b_10 = (((((e % 500) % 200) % 100) % 50) % 20) / 10;
    int b_5 = ((((((e % 500) % 200) % 100) % 50) % 20) % 10) / 5;
    int c_2 = (((((((e % 500) % 200) % 100) % 50) % 20) % 10) % 5) / 2;
    int c_1 = ((((((((e % 500) % 200) % 100) % 50) % 20) % 10) % 5) % 2);

    int c_50 = c / 50;
    int c_20 = (c % 50) / 20;
    int c_10 = ((c % 50) % 20) / 10;
    int c_5 = (((c % 50) % 20) % 10) / 5; 
    int c_02 = ((((c % 50) % 20) % 10) % 5) / 2;
    int c_01 = ((((c % 50) % 20) % 10) % 5) % 2;

    cout << "Banknotes of 500 euros: " << b_500 << endl;
    cout << "Banknotes of 200 euros: " << b_200 << endl;
    cout << "Banknotes of 100 euros: " << b_100 << endl;
    cout << "Banknotes of 50 euros: " << b_50 << endl;
    cout << "Banknotes of 20 euros: " << b_20 << endl;
    cout << "Banknotes of 10 euros: " << b_10 << endl;
    cout << "Banknotes of 5 euros: " << b_5 << endl;
    cout << "Coins of 2 euros: " << c_2 << endl;
    cout << "Coins of 1 euro: " << c_1 << endl;

    cout << "Coins of 50 cents: " << c_50 << endl;
    cout << "Coins of 20 cents: " << c_20 << endl;
    cout << "Coins of 10 cents: " << c_10 << endl;
    cout << "Coins of 5 cents: " << c_5 << endl;
    cout << "Coins of 2 cents: " << c_02 << endl;
    cout << "Coins of 1 cent: " << c_01 << endl;
}