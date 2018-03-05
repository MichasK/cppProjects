/*
 * testFactory.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: michal
 */
#include "../include/Factory.hpp"

#include "gtest/gtest.h"
TEST(Factory_Test,Factory) {
	Factory factory;
	for (int i = 0; i < 10; i++) {
		factory.addRamp(Ramp(i, 1));
		factory.addWorker(
				Worker(i, 1, std::make_shared<PackageQueue>(QueueType::LIFO)));
		Storehouse s(i);
		factory.addStorehouse(s);
	}
	ASSERT_EQ(10, factory.getRampsNoumber());
	ASSERT_EQ(10, factory.getStorehousesNoumber());
	ASSERT_EQ(10, factory.getWorkersNoumber());
	factory.removeRamp(1);
	factory.removeRamp(0);
	factory.removeWorker(1);
	factory.removeWorker(0);
	factory.removeStorehouse(0);
	factory.removeStorehouse(1);
	ASSERT_EQ(8, factory.getRampsNoumber());
	ASSERT_EQ(8, factory.getStorehousesNoumber());
	ASSERT_EQ(8, factory.getWorkersNoumber());
	auto v = factory.getRamp();
	EXPECT_EQ(v.size(), factory.getRampsNoumber());
	for (auto x : v) {
		EXPECT_NE(x.getId(), 0);
		EXPECT_NE(x.getId(), 1);
	}

}
TEST(Factory_Test,FactoryGetRamp) {
	Factory f;
	for (int i = 10; i > 2; i--) {
		f.addRamp(Ramp(i, 1));
		f.addWorker(
				Worker(i, 1, std::make_shared<PackageQueue>(QueueType::FIFO)));
		f.addStorehouse(Storehouse(i));
	}
	auto list = f.getRamp();
	auto list1 = f.getWorker();
	auto list2 = f.getStorehouse();
	int counter = 3;
	for (auto x : list) {
		EXPECT_EQ(counter, x.getId());
		counter += 1;
	}
	counter = 3;
	for (auto x : list1) {
		EXPECT_EQ(counter, x.getID());
		counter += 1;
	}
	counter = 3;
}

