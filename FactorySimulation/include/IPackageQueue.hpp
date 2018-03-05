/*
 * IPackageQueue.hpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */

#ifndef SRC_IPACKAGEQUEUE_HPP_
#define SRC_IPACKAGEQUEUE_HPP_


#include "Types.hpp"
#include "Package.hpp"
#include "IPackageDepot.hpp"



class IPackageQueue: public IPackageDepot{
public:
	virtual ~IPackageQueue(){};
	virtual Package pop()=0;
	virtual QueueType getQueueType()const=0;
};




#endif /* SRC_IPACKAGEQUEUE_HPP_ */
