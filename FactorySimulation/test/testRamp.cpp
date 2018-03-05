/*
 * testRamp.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: michal
 */

#include "gtest/gtest.h"

#include "Ramp.hpp"
#include "Rand.hpp"
#include "FactoryIO.hpp"

TEST(Ramp_Test,Ramp) {
	int _id = Rand::rndId();
	int _deliveryInterval = Rand::rndId();
	Ramp _ramp(_id, _deliveryInterval);
	ASSERT_EQ(_ramp.getId(), _id);
	ASSERT_EQ(_ramp.getDeliveryInterval(), _deliveryInterval);
}

TEST(Ramp_Test,deliverGoods) {
	Ramp _ramp(1, 2);
	auto t=_ramp.viewSiendingBuffer();
	ASSERT_EQ(t.size(), 0);
	int bufforSize(0);
	for (int i = 1; i < 10000; i++) {
		_ramp.deliverGoods(i);
		if ((i - 1) % 2 == 0) {
			bufforSize += 1;
			EXPECT_EQ(bufforSize, _ramp.viewSiendingBuffer().size());
		}
	}
}

TEST(Ramp_Test,getRaport) {
	Ramp _ramp(2, 2);
	std::unique_ptr<IPackageReceiver> v = std::make_unique<Worker>(1,2, std::make_shared<PackageQueue>(QueueType::FIFO));
	std::unique_ptr<IPackageReceiver> vv = std::make_unique<Worker>(2,2, std::make_shared<PackageQueue>(QueueType::FIFO));
	std::map<IPackageReceiver*, double> x;
	x[v.get()] = 0.3;
	x[vv.get()] = 0.7;
	_ramp.receiverPreferences.setPreferences(x);
	std::stringstream os;
	generateStructureRaportRamp(_ramp,os);
	EXPECT_EQ("LOADING RAMP #2\n  Delivery interval: 2\n  Receivers:\n    worker #1 (p = 0.3)\n    worker #2 (p = 0.7)\n",os.str());
}
