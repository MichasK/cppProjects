/*
 * testFactoryIO.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: michal
 */
#include "gtest/gtest.h"

#include "FactoryIO.hpp"

#include <fstream>

/////////////////////////////////
//Raports tests                //
/////////////////////////////////
TEST(Factory_TestOut, getRaport) {
	Worker w(1, 2, std::make_shared<PackageQueue>(QueueType::FIFO));
	std::unique_ptr<IPackageReceiver> v = std::make_unique<Worker>(1, 2,
			std::make_shared<PackageQueue>(QueueType::FIFO));
	std::unique_ptr<IPackageReceiver> vv = std::make_unique<Worker>(2, 2,
			std::make_shared<PackageQueue>(QueueType::FIFO));
	std::map<IPackageReceiver*, double> x;
	x[v.get()] = 0.5;
	x[vv.get()] = 0.5;
	w.receiverPreferences.setPreferences(x);
	std::stringstream os;
	generateStructureRaportWorker(w, os);
	EXPECT_EQ(os.str(),
			"WORKER #1\n  Processing time: 2\n  Queue type: FIFO\n  Receivers:\n    worker #1 (p = 0.5)\n    worker #2 (p = 0.5)\n");
}

/////////////////////////////////
//Load factory tests           //
/////////////////////////////////
TEST(Factory_TestIO,LoadFactory) {
	std::ostringstream oss;
	oss << "LOADING_RAMP id=1 delivery-interval=3" << "\n" << "STOREHOUSE id=1"
			<< "\n" << "STOREHOUSE id=3" << "\n" << "\n" << "STOREHOUSE id=2"
			<< "\n" << "WORKER id=1 processing-time=2 queue-type=FIFO" << "\n"
			<< "LINK src=ramp-1 dest=store-1 p=0.3" << "\n"
			<< "LINK src=ramp-1 dest=store-2 p=0.7" << "\n";
	std::istringstream iss(oss.str());
	Factory factory = loadFactoryStructure(iss);
	auto ramp_vec = factory.getRamp();
	ASSERT_EQ(ramp_vec[0].getId(), 1);
	ASSERT_EQ(ramp_vec[0].getDeliveryInterval(), 3);
	auto worker_vec = factory.getWorker();
	ASSERT_EQ(worker_vec[0].getID(), 1);
	ASSERT_EQ(worker_vec[0].getProcessingDuration(), 2);
	ASSERT_EQ(worker_vec[0].getWorkerQueueType(), QueueType::FIFO);
	ASSERT_EQ(factory.getStorehouse()[0].getID(), 1);
	ASSERT_EQ(factory.getStorehouse()[1].getID(), 2);
	auto key =
			dynamic_cast<IPackageReceiver*>(const_cast<Storehouse*>(&(*factory.findStorehouseById(
					1))));
	auto map_wiev =
			factory.findRampById(1)->receiverPreferences.getPreferences();
	EXPECT_DOUBLE_EQ(map_wiev.at(key), 0.3);
	key =
			dynamic_cast<IPackageReceiver*>(const_cast<Storehouse*>(&(*factory.findStorehouseById(
					2))));
	EXPECT_DOUBLE_EQ(map_wiev.at(key), 0.7);
}
TEST(FactoryIO_Test,LoadFactoryFromFile) {
	std::ostringstream oss;
	std::ifstream file("/home/michal/CLionProjects/FactorySimulation/struct-input.txt", std::ifstream::in);
	std::string tmpLine;
	while (std::getline(file, tmpLine)) {
		oss << tmpLine << "\n";
	}
	std::istringstream iss(oss.str());
	Factory factory = loadFactoryStructure(iss);
	auto worker_vec = factory.getWorker();
	auto store_vec = factory.getStorehouse();
	auto ramp_vec = factory.getRamp();
	auto map_wiev =
			factory.findRampById(1)->receiverPreferences.getPreferences();
	auto key =
			dynamic_cast<IPackageReceiver*>(const_cast<Worker*>(&(*factory.findWorkerById(
					1))));
	EXPECT_DOUBLE_EQ(map_wiev.at(key), 1.0);
	map_wiev =
			factory.findRampById(2)->receiverPreferences.getPreferences();
	key =
			dynamic_cast<IPackageReceiver*>(const_cast<Worker*>(&(*factory.findWorkerById(
					1))));
	EXPECT_DOUBLE_EQ(map_wiev.at(key), 0.3);
	key =
			dynamic_cast<IPackageReceiver*>(const_cast<Worker*>(&(*factory.findWorkerById(
			2))));
	EXPECT_DOUBLE_EQ(map_wiev.at(key), 0.7);
}
TEST(FactoryIO_Test,LoadFactoryExceptions){
	std::istringstream iss("LINK src=ramp-1 dest=worker-1 p=0.5");// No Worker(1)
	ASSERT_THROW(loadFactoryStructure(iss);,std::runtime_error);
	iss.clear();
	iss .str("STH src=worker-1 dest=worker-1 p=0.5");// STH is not Ramp,Store nor Worker
	ASSERT_THROW(loadFactoryStructure(iss);,std::runtime_error);
}
