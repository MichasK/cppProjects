/*
 * ReceiverPreferences.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */
#include "ReceiverPreferences.hpp"

#include <exception>

void verifyProbability(double probability) {
	if (probability < 0.0 || probability > 1.0) {
		throw std::logic_error(
				"Probability out of the range of [0,1], was: "
						+ std::to_string(probability));
	}
}


void ReceiverPreferences::setPreferences(
		std::map<IPackageReceiver*, double> preferences) {
	double total_probability;
	for (const auto& x : preferences) {
		double probability = x.second;
		verifyProbability(probability);
		total_probability += probability;
	}
	verifyProbability(total_probability);
	probabilities = preferences;
}

void ReceiverPreferences::addReceiver(IPackageReceiver* receiver_ptr) {
	probabilities[receiver_ptr] = 0;
	double new_normal_probability = (double) 1 / probabilities.size();
	for (auto&x : probabilities) {
		x.second = new_normal_probability;
	}
}

void ReceiverPreferences::addReceiverWithProbability(
		IPackageReceiver* receiver_ptr, double receiver_ptr_prob) {
	if (probabilities.empty()) {
		throw std::logic_error("Cannot add a receiver, empty set!");
	}
	for (auto& x : probabilities) {
		x.second = (double) (1 - receiver_ptr_prob) * x.second;
	}
	probabilities[receiver_ptr] = receiver_ptr_prob;

}

void ReceiverPreferences::removeReceiver(IPackageReceiver* receiver_ptr) {
	auto elem = probabilities.find(receiver_ptr);
	bool elemWasFound = (elem != probabilities.end());
	if (elemWasFound) {
		double FoundElemProb = elem->second;
		probabilities.erase(elem);
		for (auto &x : probabilities) {
			x.second = (double) x.second / (1 - FoundElemProb);
		}
	}
}

IPackageReceiver* ReceiverPreferences::drawReceiver(double random) {
	double sth = 0;
	for (const auto &x : probabilities) {
		sth += x.second;
		if (random <= sth)
			return x.first;
	}
	throw std::logic_error("No receiver was drawn!");
}

std::vector<std::pair<IPackageReceiver*, double>> ReceiverPreferences::view() const {
	std::vector<std::pair<IPackageReceiver*, double>> v;
	for (const auto& x : probabilities) {
		std::pair<IPackageReceiver*, double> p(x.first, x.second);
		v.push_back(p);
	}
	return v;
}
