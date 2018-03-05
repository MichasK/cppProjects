/*
 * Storehouse.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: michal
 */
#include "../include/Storehouse.hpp"

void Storehouse::receivePackage(Package _package) {
	packageDepot->push(_package);
}

std::vector<Package> Storehouse::viewDepot() const {
	return packageDepot->view();
}

ReceiverType Storehouse::getReceiverType() const {
	return ReceiverType::STOREHOUSE;
}
ElementID Storehouse::getID() const {
	return storehouse_id;
}
