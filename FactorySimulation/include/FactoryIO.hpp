/*
 * FactoryIO.hpp
 *
 *  Created on: Feb 14, 2018
 *      Author: michal
 */

#ifndef INCLUDE_FACTORYIO_HPP_
#define INCLUDE_FACTORYIO_HPP_


#include "Ramp.hpp"
#include "Worker.hpp"
#include "Factory.hpp"
#include "Package.hpp"
#include "Storehouse.hpp"
#include "ReceiverPreferences.hpp"

#include <string>
#include <vector>
#include <iostream>

Factory loadFactoryStructure(std::istream&);

void  generateStructureRaport(const Factory&,std::ostream&);
void generateStructureRaportRamp(const Ramp&,std::ostream&);
void generateStructureRaportWorker(const Worker&,std::ostream&);
void generateStructureRaportStorehouse(const Storehouse&,std::ostream&);
void generateStructureRaportReceiver(const ReceiverPreferences&,std::ostream&);


void generateSimulationTurnReport(const Factory&,std::ostream&,Time);
void generateSimulationTurnWorker(const Worker&,std::ostream&,Time);
void generateSimulationTurnStorehouse(const Storehouse&,std::ostream&);
void generateSimulationTurnQueue(const std::vector<Package>&,std::ostream&);

#endif /* INCLUDE_FACTORYIO_HPP_ */
