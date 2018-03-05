/*
 * PackageSender.hpp
 *
 *  Created on: Feb 2, 2018
 *      Author: michal
 */

#ifndef INCLUDE_PACKAGESENDER_HPP_
#define INCLUDE_PACKAGESENDER_HPP_

#include "Package.hpp"
#include "ReceiverPreferences.hpp"

#include <vector>

class PackageSender{
protected:
	std::vector<Package> sendingBuffer;
public:
	ReceiverPreferences receiverPreferences;
	void sendPackage();
	std::vector<Package> viewSiendingBuffer()const{return sendingBuffer;};
	void pushPackage(Package& package) { sendingBuffer.push_back(package); }
	void pushPackage(Package&& package) { sendingBuffer.push_back(package); }
};

#endif /* INCLUDE_PACKAGESENDER_HPP_ */
