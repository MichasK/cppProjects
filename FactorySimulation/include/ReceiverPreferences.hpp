/*
 * ReceiverPreferences.hpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */

#ifndef SRC_RECEIVERPREFERENCES_HPP_
#define SRC_RECEIVERPREFERENCES_HPP_

#include "Types.hpp"
#include "IPackageReceiver.hpp"

#include <map>
#include <memory>
#include <utility>//for std::pair

class ReceiverPreferences{
private:
	std::map<IPackageReceiver*,double> probabilities;
public:
	const std::map<IPackageReceiver*,double>& getPreferences()const{return probabilities;};
	void setPreferences(std::map<IPackageReceiver*,double>);
	void addReceiver(IPackageReceiver*);
	void addReceiverWithProbability(IPackageReceiver*,double);
	void removeReceiver(IPackageReceiver*);
	IPackageReceiver* drawReceiver(double);
	std::vector<std::pair<IPackageReceiver*,double>> view()const;
};
void verifyProbability(double probability);



#endif /* SRC_RECEIVERPREFERENCES_HPP_ */
