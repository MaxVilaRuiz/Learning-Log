#include <iostream>
#include <random>
#include "rng.hh"

using namespace std;

int main() {
	RNG rng;
	rng_init(rng);

	vector<int> histograma(10, 0);
	for (int i = 0; i < 1000000; i++) {
		int x = rng_generate(rng, 0, 9);
		histograma[x]++;
	}

	for (int i = 0; i < histograma.size(); i++) {
		cout << i << ": " << histograma[i] << endl;
	}

    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << rng_generate(rng, 0.0, 1.0) << endl;
    }
}