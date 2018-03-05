/*
 * Ramp.hpp
 *
 *  Created on: Feb 2, 2018
 *      Author: michal
 */

#ifndef INCLUDE_RAMP_HPP_
#define INCLUDE_RAMP_HPP_

#include "Types.hpp"
#include "PackageSender.hpp"

class Ramp:public PackageSender{
private:
	ElementID id;
	TimeOffset deliveryInterval;
public:
	Ramp(ElementID _id,TimeOffset _deliveryInterval):id(_id),deliveryInterval(_deliveryInterval){};
	Ramp(const Ramp& r):id(r.getId()),deliveryInterval(r.getDeliveryInterval()){};
	bool operator==(const Ramp& ramp){return ramp.getId()==id && deliveryInterval==ramp.getDeliveryInterval();}
	void deliverGoods(Time);
	TimeOffset getDeliveryInterval()const{return deliveryInterval;};
	ElementID getId()const{return id;};

};



#endif /* INCLUDE_RAMP_HPP_ */
