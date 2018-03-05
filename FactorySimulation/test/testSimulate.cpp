/*
 * testSimulate.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: michal
 */

#include "../include/FactoryIO.hpp"
#include "../include/Simulation.hpp"
#include "gtest/gtest.h"
// TODO ALL simulation tests

TEST(Simulation_test,RampAndStorehouseLink) {
	std::ostringstream oss;
	oss << "LOADING_RAMP id=1 delivery-interval=1" << "\n" << "STOREHOUSE id=1"
			<< "\n" << "WORKER id=1 processing-time=3 queue-type=FIFO" << "\n"
			<< "LINK src=ramp-1 dest=store-1 p=1.0" << "\n";
	std::istringstream iss(oss.str());
	Factory factory = loadFactoryStructure(iss);
	simulate(factory,5);
}
