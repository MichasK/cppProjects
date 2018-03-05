/*
 * testStorehouse.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: michal
 */
#include "gtest/gtest.h"


#include "Rand.hpp"
#include "Storehouse.hpp"
#include "FactoryIO.hpp"

#include <string>

TEST(Storehouse_Test, Storehouse){
	auto id=Rand::rndId();
	Storehouse x(id);
	EXPECT_EQ(id,x.getID());
}

TEST(Storehouse_Test, getReceiverType){
	Storehouse x(1);
	EXPECT_EQ(ReceiverType::STOREHOUSE,x.getReceiverType());
}

TEST(Storehouse_Test, receivePackage){
	Storehouse x(1);
	EXPECT_EQ(ReceiverType::STOREHOUSE,x.getReceiverType());
	auto package_number=Rand::rndId();
	for(int i=0;i<package_number;i++){
		x.receivePackage(Package());
	}
	auto vec_view=x.viewDepot();
	ASSERT_EQ(package_number,vec_view.size());

}

TEST(Storehouse_Test, getRaport){
	Storehouse x(1);
	std::stringstream os;
	generateStructureRaportStorehouse(x,os);
	EXPECT_EQ("STOREHOUSE #1\n",os.str());
}

TEST(Storehouse_Test, reveivePackagefromWorker){
	Storehouse s(10);
	s.receivePackage(Package());
	EXPECT_EQ(s.size(),1);

}

TEST(Storehouse_Test, getSimulationRaport){
	std::stringstream report;
	std::ostringstream inputstring;
	inputstring << "  STOREHOUSE #1\n    Queue: #2, \n";
	Storehouse s(1);
	s.receivePackage(Package(2));
	generateSimulationTurnStorehouse(s,report);
	ASSERT_EQ(inputstring.str(),report.str());
}

