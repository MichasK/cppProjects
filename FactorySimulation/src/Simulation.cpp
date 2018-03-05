/*
 * Simulation.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: michal
 */
#include "../include/Simulation.hpp"
#include "../include/FactoryIO.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

void simulate(Factory& f, TimeOffset simDuration) {
	std::stringstream os;
	for (Time turn = 1; turn <= simDuration; ++turn) {
		//Ramps are receiving goods
		std::for_each(f.ramp_begin(), f.ramp_end(), [&](Ramp& ramp) {
			ramp.deliverGoods(turn);});

		//Goods are sending from Ramps and Worker to their receivers
		std::for_each(f.ramp_begin(), f.ramp_end(), [&](Ramp& ramp) {
			ramp.sendPackage();});
		std::for_each(f.worker_begin(), f.worker_end(), [&](Worker& worker) {
			worker.sendPackage();});
		//Workers are processing their tasks
		std::for_each(f.worker_begin(), f.worker_end(), [&](Worker& worker) {
			worker.doWork(turn);});
		os << turn << "\n";
		generateSimulationTurnReport(f, os, turn);
		std::cout << os.str();
		os.str("");
	}
}

