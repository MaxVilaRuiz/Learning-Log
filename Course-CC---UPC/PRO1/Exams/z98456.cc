#include <cassert>
#include <iostream>
using namespace std;

/**
 * @pre a != b, rep1, rep2 > 0
 * @post Returns an bicolor number of the form: a^nb^m, where n, m > 0
 */
int make_bicolor(int a, int b, int rep1, int rep2) {
	assert(a != b && rep1 > 0 && rep2 > 0);
	int n = 0;
	for (int i = 0; i < rep1; i++) {
		n = n * 10 + a;
	}
	for (int i = 0; i < rep2; i++) {
		n = n * 10 + b;
	}
	return n;
}


int main() {
	int num_xifres;
	cin >> num_xifres;

	assert(num_xifres > 1 && num_xifres < 10);

	for (int d1 = 1; d1 <= 9; d1++) {
		for (int d2 = 0; d2 <= 9; d2++) {
			if (d1 != d2) {
				for (int r = 1; r < num_xifres; r++) {
					cout << make_bicolor(d1, d2, r, num_xifres - r) << endl;
				}
			}
		}
	}
}
