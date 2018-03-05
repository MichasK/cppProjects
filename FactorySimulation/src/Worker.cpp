/*
 * Worker.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: michal
 */
#include "../include/Worker.hpp"

void Worker::doWork(Time _currentTime) {
	bool IsInert = (packageProcessingStartTime == 0);
	if (IsInert && !queue->isEmpty()) {
		currentlyProcessedPackage.push_back(queue->pop());
		packageProcessingStartTime = _currentTime;
	}
	bool processingIsFinished = _currentTime - packageProcessingStartTime
			== processingDuration - 1;
	if (processingIsFinished) {
		if (currentlyProcessedPackage.size() != 0) {
			Package p = currentlyProcessedPackage.back();
			currentlyProcessedPackage.pop_back();
			pushPackage(p);
			packageProcessingStartTime = 0;
		}
	}

}
