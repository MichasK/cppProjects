/*
 * IPackageReceiver.hpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */

#ifndef SRC_IPACKAGERECEIVER_HPP_
#define SRC_IPACKAGERECEIVER_HPP_

#include "Types.hpp"
#include "Package.hpp"

#include <vector>

class IPackageReceiver{
public:
	virtual ~IPackageReceiver(){};
	virtual void receivePackage(Package)=0;
	virtual std::vector<Package>viewDepot()const=0;
	virtual ReceiverType getReceiverType()const=0;
	virtual ElementID getID()const=0;

};


#endif /* SRC_IPACKAGERECEIVER_HPP_ */
