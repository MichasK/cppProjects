/*
 * Worker.hpp
 *
 *  Created on: Feb 3, 2018
 *      Author: michal
 */

#ifndef INCLUDE_WORKER_HPP_
#define INCLUDE_WORKER_HPP_

#include "Types.hpp"
#include "PackageQueue.hpp"
#include "PackageSender.hpp"
#include "IPackageQueue.hpp"
#include "IPackageReceiver.hpp"

#include<memory>
#include<vector>

class Worker:public IPackageReceiver, public PackageSender{
private:
	ElementID id;
	TimeOffset processingDuration;
	Time packageProcessingStartTime=0;
	std::shared_ptr<IPackageQueue>  queue;
	std::vector<Package> currentlyProcessedPackage;
public:
	Worker(ElementID _id,TimeOffset _procDuration,std::shared_ptr<IPackageQueue> _queue):id(_id),
	processingDuration(_procDuration),queue(std::move(_queue)){};

	void receivePackage(Package _package)override{queue->push(_package);};
	std::vector<Package> viewDepot()const{return queue->view();};
	void doWork(Time);
	ElementID processedPackageId()const{if(!currentlyProcessedPackage.empty())return currentlyProcessedPackage[0].getID();}
	bool isBuforEmpty()const{return sendingBuffer.empty();}

	TimeOffset getProcessingDuration()const{return processingDuration;};
	Time getPackageProcessingStartTime()const{return packageProcessingStartTime;};
	ReceiverType getReceiverType()const{return ReceiverType::WORKER;};
	ElementID getID()const override{return id;};
	QueueType getWorkerQueueType()const{return queue->getQueueType();}

	friend void generateSimulationTurnWorker(const Worker&, std::ostream&,Time);
};


#endif /* INCLUDE_WORKER_HPP_ */
