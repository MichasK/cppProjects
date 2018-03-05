/*
 * Package.hpp
 *
 *  Created on: Jan 26, 2018
 *      Author: michal
 */

#ifndef PACKAGE_HPP_
#define PACKAGE_HPP_

#include "Types.hpp"

#include <cstddef>

class Package {
private:
	ElementID id=-1;
public:
	Package():id(Package::counter){Package::counter +=1;};
	Package(ElementID _id):id(_id){};
	int getID()const{return id;};
private:
	static int counter;
};

#endif /* PACKAGE_HPP_ */

