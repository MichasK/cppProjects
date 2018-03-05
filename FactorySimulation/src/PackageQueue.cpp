/*
 * PackageQueue.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: michal
 */
#include "PackageQueue.hpp"

/*
 * This Constructor do not filful Open-Close principle, but LIFO, FIFO and FEFO(unsupported, can be add
 * by adding one "if-else"
 *	 	 	 	 	 	 	*/

PackageQueue::PackageQueue(QueueType _queueType) {
	PackageQueueType = _queueType;
	if (_queueType == QueueType::FIFO) {
		_popFunction =
				[this]() {Package _package = deque.front();deque.pop_front();return _package;};
	} else {
		if (_queueType == QueueType::LIFO) {
			_popFunction =
					[this]() {Package _package = deque.back();deque.pop_back();return _package;};
		} else {
			throw std::runtime_error("Unsupported queue type");
		}
	}

}
