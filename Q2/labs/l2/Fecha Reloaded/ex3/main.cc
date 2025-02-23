// g++ -o fechas main.cc fecha.cc

#include <iostream>
#include <vector>
#include "fecha.hh"
using namespace std;


void sort_v (vector<Fecha>& v) {
	for (int i = 1; i < v.size(); i++) {
		int pos = i;
		Fecha ini_value = v[pos];

		while (pos >= 0 && ini_value.menor(v[pos-1])) {
			v[pos] = v[pos-1];
			pos--;
		}

		v[pos] = ini_value;
	}
}


int main() {
	vector<Fecha> v;
	Fecha data;

	while (cin >> data) {
		v.push_back(data);
	}

	sort_v(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}