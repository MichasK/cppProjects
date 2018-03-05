/*
 * IPackageDepot.hpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */

#ifndef SRC_IPACKAGEDEPOT_HPP_
#define SRC_IPACKAGEDEPOT_HPP_

#include "Types.hpp"
#include "Package.hpp"

#include <vector>

class IPackageDepot {
public:
	virtual ~IPackageDepot() {};
	virtual void push(Package& _package)=0;
	virtual bool isEmpty() const=0;
	virtual int size() const=0;
	virtual std::vector<Package> view() const=0;
};
#endif /* SRC_IPACKAGEDEPOT_HPP_ */
