/*
 * Factory.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: michal
 */
#include "Factory.hpp"

void Factory::removeRamp(ElementID _id) {
	auto it = std::find_if(ramps.begin(), ramps.end(),
			[_id](const Ramp& x) {return (x.getId() == _id);});
	if (it != ramps.end()) {
		ramps.erase(it);
	}
}

void Factory::removeStorehouse(ElementID _id) {
	auto it = std::find_if(storehouses.begin(), storehouses.end(),
			[_id](const Storehouse& x) {return (x.getID() == _id);});
	if (it != storehouses.end()) {
		storehouses.erase(it);
	}
}
void Factory::removeWorker(ElementID _id) {
	auto it = std::find_if(workers.begin(), workers.end(),
			[_id](const Worker& x) {return (x.getID() == _id);});
	if (it != workers.end()) {
		workers.erase(it);
	}
}
std::vector<Ramp> Factory::getRamp() const {
	std::vector<Ramp> v(ramp_begin(), ramp_end());
	std::sort(v.begin(), v.end(),
			[&](Ramp a, Ramp b) {return a.getId() < b.getId();});
	return v;
}
std::vector<Storehouse> Factory::getStorehouse() const {
	std::vector<Storehouse> v { std::begin(storehouses), std::end(storehouses) };
	std::sort(v.begin(), v.end(),
			[](Storehouse a, Storehouse b) {return a.getID() < b.getID();});
	return v;
}
std::vector<Worker> Factory::getWorker() const {
	std::vector<Worker> v { std::begin(workers), std::end(workers) };
	std::sort(v.begin(), v.end(),
			[](Worker a, Worker b) {return a.getID() < b.getID();});
	return v;
}
