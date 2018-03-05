/*
 * Rand.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: michal
 */
#include <time.h>
#include <stdlib.h>
#include <random>
#include <cmath>
#include "../include/Rand.hpp"
#include "../include/ReceiverPreferences.hpp"
int Rand::rndId() {
	srand(time( NULL));
	return rand() % 1000;
}
double Rand::rndProbability() {
	srand(time( NULL));
	double return_probability;
	return_probability = (double) rand() / RAND_MAX;
	verifyProbability(return_probability);
	return return_probability;
}
double Rand::rndProbabilityNormalDistribution() {
	std::random_device rd { };
	std::mt19937 gen { rd() };
	std::normal_distribution<double> d { 0, 1 };
	std::uniform_real_distribution<> prob(0.0, 1.0);
	double return_probability = prob(gen);
	verifyProbability(return_probability);
	return return_probability;
}
