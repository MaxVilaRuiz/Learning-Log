#include <iostream>
#include <random>
#ifndef RNG_HH
#define RNG_HH

struct RNG {
	std::random_device device;
	std::mt19937		  generator;
};


void rng_init(RNG& rng);

int rng_generate(RNG& rng, int min, int max);

double rng_generate(RNG& rng, double min, double max);


#endif