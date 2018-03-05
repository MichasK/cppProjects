/*
 * FactoryIO.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: michal
 */
#include "FactoryIO.hpp"

#include <string>
#include <iostream>

std::string getReceiverType(IPackageReceiver* rec) {
	if (rec->getReceiverType() == ReceiverType::WORKER)
		return "worker";
	else
		return "storehouse";
}

std::string getQueueType(const Worker& worker) {
	if (worker.getWorkerQueueType() == QueueType::LIFO)
		return "LIFO";
	else
		return "FIFO";
}

QueueType getQueueType(const std::string& str) {
	if (str == "FIFO")
		return QueueType::FIFO;
	else
		return QueueType::LIFO;
}

void generateStructureRaportRamp(const Ramp& ramp, std::ostream& os) {
	os << "LOADING RAMP #" << ramp.getId() << "\n";
	os << "  " << "Delivery interval: " << ramp.getDeliveryInterval() << "\n";
	os << "  " << "Receivers:" << "\n";
	generateStructureRaportReceiver(ramp.receiverPreferences, os);
}
void generateStructureRaportReceiver(const ReceiverPreferences& recPreferences,
		std::ostream& os) {
	auto pref = recPreferences.view();
	std::sort(pref.begin(), pref.end(),
			[](const std::pair<IPackageReceiver*,double> a,const std::pair<IPackageReceiver*,double>b) {
				return a.first->getID()<b.first->getID();
			});
	for (auto x : pref) {
		os << "    " << getReceiverType(x.first) << " #" << x.first->getID();
		os << " (p = " << x.second << ")" << "\n";
	}
}

void generateStructureRaportWorker(const Worker& worker, std::ostream& os) {
	os << "WORKER #" << worker.getID() << "\n";
	os << "  Processing time: " << worker.getProcessingDuration() << "\n";
	os << "  Queue type: " << getQueueType(worker) << "\n";
	os << "  " << "Receivers:" << "\n";
	generateStructureRaportReceiver(worker.receiverPreferences, os);
}
void generateStructureRaportStorehouse(const Storehouse& storehouse,
		std::ostream& os) {
	os << "STOREHOUSE #" << storehouse.getID() << "\n";
}

void generateStructureRaport(const Factory& factory, std::ostream& os) {
	os << "\n== LOADING RAMPS ==" << "\n";
	auto ramps = factory.getRamp();
	for (auto x : ramps) {
		os << "\n";
		generateStructureRaportRamp(x, os);
	}
	os << "\n== WORKERS ==" << "\n";
	auto workers = factory.getWorker();
	for (auto x : workers) {
		os << "\n";
		generateStructureRaportWorker(x, os);
	}
	os << "\n== STOREHOUSES ==" << "\n";
	auto storehouses = factory.getStorehouse();
	for (auto x : storehouses) {
		os << "\n";
		generateStructureRaportStorehouse(x, os);
	}
}

void generateSimulationTurnReport(const Factory& factory, std::ostream& os,
		Time currentTime) {

	os << "== WORKERS ==\n";
	std::for_each(factory.worker_begin(), factory.worker_end(),
			[&](const Worker& w) {
				generateSimulationTurnWorker(w, os, currentTime);
				os << "\n";});
	os << "== STOREHOUSES ==\n\n";
	std::for_each(factory.storehouse_begin(), factory.storehouse_end(),
			[&](const Storehouse& s) {
				generateSimulationTurnStorehouse(s, os);});

}

void generateSimulationTurnWorker(const Worker& worker, std::ostream& os,
		Time currentTime) {
	os << "  WORKER #" << worker.getID() << "\n";
	os << "    Queue: ";
	auto sendingBuf = worker.sendingBuffer;
	auto v = worker.viewDepot();
	if(currentTime==1)os << "#" << worker.processedPackageId() << " (pt = 1)";
	if (!sendingBuf.empty()) {
		os << "#" << sendingBuf[0].getID() << " (pt = "
				<< worker.getProcessingDuration() << ") ";
	} else if (!v.empty()) {
		os << "#" << worker.processedPackageId() << " (pt = "
				<< currentTime - worker.getPackageProcessingStartTime() + 1
				<< ") ";
	}
	generateSimulationTurnQueue(v, os);
}

void generateSimulationTurnStorehouse(const Storehouse& storehouse,
		std::ostream& os) {
	os << "  STOREHOUSE #" << storehouse.getID() << "\n";
	os << "    Queue: ";
	generateSimulationTurnQueue(storehouse.viewDepot(), os);
}

void generateSimulationTurnQueue(const std::vector<Package>& queue,
		std::ostream& os) {
	for (auto x : queue) {
		os << "#" << x.getID() << ", ";
	}
	os << "\n";
}

std::vector<std::string> ParseSplit(const std::string& str,
		const std::string& delim) {
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do {
		pos = str.find(delim, prev);
		if (pos == std::string::npos)
			pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty())
			tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

Factory loadFactoryStructure(std::istream& is) {
	Factory factory;
	std::string line;
	std::map<std::string, std::map<IPackageReceiver*, double>> links;
	while (std::getline(is, line)) {
		bool lineIsEmpty = line.empty() || isblank(line[0]);
		bool commentLine = !line.empty() && line[0] == ';';
		if (lineIsEmpty || commentLine)
			continue;
		auto delimitedLine = ParseSplit(line, " ");
		if (delimitedLine[0] == "LOADING_RAMP") {
			ElementID id = stoi(
					delimitedLine[1].substr(delimitedLine[1].find("=") + 1));
			TimeOffset deliveryInterval = stoi(
					delimitedLine[2].substr(delimitedLine[2].find("=") + 1));
			Ramp r(id, deliveryInterval);
			factory.addRamp(r);
		} else if (delimitedLine[0] == "WORKER") {
			ElementID id = stoi(
					delimitedLine[1].substr(delimitedLine[1].find("=") + 1));
			TimeOffset processingtime = stoi(
					delimitedLine[2].substr(delimitedLine[2].find("=") + 1));
			auto queueType = getQueueType(
					delimitedLine[3].substr(delimitedLine[3].find("=") + 1));
			Worker w(id, processingtime,
					std::make_shared<PackageQueue>(queueType));
			factory.addWorker(w);
		} else if (delimitedLine[0] == "STOREHOUSE") {
			ElementID id = stoi(
					delimitedLine[1].substr(delimitedLine[1].find("=") + 1));
			Storehouse s(id);
			factory.addStorehouse(s);
		} else if (delimitedLine[0] == "LINK") {
			auto p = delimitedLine[2].find("-");
			std::string nodeType = delimitedLine[2].substr(
					delimitedLine[2].find('=') + 1,
					delimitedLine[2].find("-") - delimitedLine[2].find('=')
							- 1);
			std::string id = delimitedLine[2].substr(p + 1);
			auto destinationData = std::make_pair(nodeType, stoi(id, nullptr));
			IPackageReceiver* packagereceiver_ptr;
			if (destinationData.first == "worker") {
				auto p = factory.findWorkerById(destinationData.second);
				if (p == factory.worker_end()) {
					throw std::runtime_error(
							"No package receiver was found while parsing input file: Id was "
									+ destinationData.second);
				}
				packagereceiver_ptr = &(*p);
			} else if (destinationData.first == "store") {
				auto p = factory.findStorehouseById(destinationData.second);
				if (p == factory.storehouse_end()) {
					throw std::runtime_error(
							"No package receiver was found while parsing input file: Id was "
									+ destinationData.second);
				}
				packagereceiver_ptr = &(*p);
			} else {
				throw std::runtime_error(
						"Invalid destination while parsing input file:"
								+ destinationData.first);
			}
			double probability = stod(
					delimitedLine[3].substr(delimitedLine[3].find("=") + 1));
			links[delimitedLine[1].substr(delimitedLine[3].find("="))][packagereceiver_ptr] =
					probability;
		} else {
			throw std::runtime_error(
					"Invalid Node type while parsing input file:"
							+ delimitedLine[0]);
		}
	}
	for (const auto& input : links) {
		auto sourceDataType = input.first.substr(input.first.find('=') + 1,
				input.first.find('-') - input.first.find('=') - 1);
		auto sourceDataID = stoi(input.first.substr(input.first.find('-') + 1));
		PackageSender* packagesender_ptr;
		if (sourceDataType == "ramp") {
			auto p = factory.findRampById(sourceDataID);
			if (p == factory.ramp_end()) {
				throw std::runtime_error(
						"No package sender was found while parsing input file: Id was "
								+ sourceDataID);
			}
			packagesender_ptr = &(*p);
		} else if (sourceDataType == "worker") {
			auto p = factory.findWorkerById(sourceDataID);
			if (p == factory.worker_end()) {
				throw std::runtime_error(
						"No package sender was found while parsing input file: Id was "
								+ sourceDataID);
			}
			packagesender_ptr = &(*p);
		} else {
			throw std::runtime_error(
					"Invalid source type while parsing input file: : "
							+ sourceDataType);
		}

		packagesender_ptr->receiverPreferences.setPreferences(input.second);
	}
	return factory;
}

