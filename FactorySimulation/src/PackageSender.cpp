/*
 * PackageSender.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: michal
 */
#include "../include/PackageSender.hpp"
#include "../include/Rand.hpp"

void PackageSender::sendPackage() {
	for (const auto package : sendingBuffer) {
		auto prob = Rand::rndProbability();
		auto receiver = receiverPreferences.drawReceiver(prob);
		receiver->receivePackage(package);
	}
	sendingBuffer.clear();
}

