/*
 * test_factorial.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: michal
 */

//test_factorial.cpp
# include "gtest/gtest.h"

#include "Types.hpp"
#include "Package.hpp"
#include "Storehouse.hpp"
#include "ReceiverPreferences.hpp"

#include <deque>
#include <memory>
#include <vector>

TEST(PackageQueue_Test,Constructor) {
	PackageQueue a(QueueType::FIFO);
	PackageQueue b(QueueType::LIFO);
	EXPECT_EQ(a.getQueueType(), QueueType::FIFO);
	EXPECT_EQ(b.getQueueType(), QueueType::LIFO);
}

TEST(PackageQueue_Test, DequeueFIFO) {
	PackageQueue b(QueueType::FIFO);
	Package x;
	Package y;
	x=y;
	EXPECT_EQ(x.getID(),y.getID());
	std::deque<Package> a;
	for (int i = 0; i < 10; i++) {
		Package p;
		b.push(p);
		a.push_back(p);
	}
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(b.pop().getID(), a.front().getID());
		a.pop_front();

	}

}

TEST(PackageQueue_Test, DequeueLIFO) {
	PackageQueue b(QueueType::LIFO);
	std::deque<Package> a;
	for (int i = 0; i < 10; i++) {
		Package p;
		b.push(p);
		a.push_back(p);
	}
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(b.pop().getID(), a.back().getID());
		a.pop_back();
	}
}
TEST(ReceiverPreferences_add_remove,Receiver) {
	ReceiverPreferences t;
	std::unique_ptr<IPackageReceiver> v = std::make_unique<Storehouse>(10);
	std::unique_ptr<IPackageReceiver> vv = std::make_unique<Storehouse>(11);
	std::unique_ptr<IPackageReceiver> vvv = std::make_unique<Storehouse>(12);
	std::map<IPackageReceiver*, double> x;
	x[v.get()] = 0.4;
	x[vv.get()] = 0.6;
	t.setPreferences(x);
	t.addReceiverWithProbability(vvv.get(), 0.2);
	auto map_wiev = t.getPreferences();
	EXPECT_DOUBLE_EQ(map_wiev.at(v.get()), 0.32);
	EXPECT_DOUBLE_EQ(map_wiev.at(vv.get()), 0.48);
	EXPECT_DOUBLE_EQ(map_wiev.at(vvv.get()), 0.2);
	t.removeReceiver(vvv.get());
	map_wiev = t.getPreferences();
	EXPECT_DOUBLE_EQ(map_wiev.at(v.get()), 0.4);
	EXPECT_DOUBLE_EQ(map_wiev.at(vv.get()), 0.6);
	t.addReceiver(vvv.get());
	map_wiev = t.getPreferences();
	EXPECT_DOUBLE_EQ(map_wiev.at(vv.get()), (double )1 / 3);
}



