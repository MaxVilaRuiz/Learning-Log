#include <iostream>
#include <random>
#include "rng.hh"

/**
 * @brief Inicializa un generador de números aleatorios declarado previamente
 */
void rng_init(RNG& rng) {
	rng.generator = std::mt19937(rng.device());
}

/**
 * @brief Genera un entero al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
int rng_generate(RNG& rng, int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(rng.generator);
}

/**
 * @brief Genera un real al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
double rng_generate(RNG& rng, double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(rng.generator);
}