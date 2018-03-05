/*
 * Storehouse.hpp
 *
 *  Created on: Jan 29, 2018
 *      Author: michal
 */

#ifndef SRC_STOREHOUSE_HPP_
#define SRC_STOREHOUSE_HPP_

#include "Types.hpp"
#include "PackageQueue.hpp"
#include "IPackageDepot.hpp"
#include "IPackageReceiver.hpp"

#include <memory>
#include <vector>

class Storehouse:public IPackageReceiver{
private:
	ElementID storehouse_id;
	std::shared_ptr<IPackageDepot> packageDepot;
public:
	Storehouse(ElementID _id):storehouse_id(_id), packageDepot(std::make_unique<PackageQueue>(QueueType::FIFO)) {};
	void receivePackage(Package)override;
	std::vector<Package>viewDepot()const override;
	ReceiverType getReceiverType()const;
	ElementID getID()const override;
	int size()const{return packageDepot->size();}
};

#endif /* SRC_STOREHOUSE_HPP_ */
