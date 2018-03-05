/*
 * Ramp.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: michal
 */

#include "../include/Ramp.hpp"

void Ramp::deliverGoods(Time currentTime) {
	if ((currentTime - 1) % deliveryInterval == 0) {
		sendingBuffer.push_back(Package());
	}

}
