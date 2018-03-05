/*
 * PackageQueue.hpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */

#ifndef SRC_PACKAGEQUEUE_HPP_
#define SRC_PACKAGEQUEUE_HPP_

#include "Types.hpp"
#include "Package.hpp"
#include "IPackageQueue.hpp"

#include <deque>
#include <functional>


class PackageQueue: public IPackageQueue {
private:
	QueueType PackageQueueType;
	std::deque<Package> deque;
	std::function<Package()> _popFunction;
public:
	PackageQueue(QueueType _queueType);
	~PackageQueue(){};
	void push(Package& _package) override{deque.push_back(_package);};
	Package pop() override{return _popFunction();};
	std::vector<Package> view() const override{return std::vector<Package> {deque.begin(),deque.end()};};
	QueueType getQueueType() const override{return PackageQueueType;};
	bool isEmpty() const override{return deque.empty();};
	int size() const override{return deque.size();};

};

#endif /* SRC_PACKAGEQUEUE_HPP_ */
