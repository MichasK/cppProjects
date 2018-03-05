/*
 * Rand.hpp
 *
 *  Created on: Jan 30, 2018
 *      Author: michal
 */

#ifndef SRC_RAND_HPP_
#define SRC_RAND_HPP_
#include <cstdlib>
#include <cstdio>
#include <ctime>
namespace Rand{
    int rndId();
    double rndProbability();
    double rndProbabilityNormalDistribution();
};
#endif /* SRC_RAND_HPP_ */
