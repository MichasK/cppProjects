/*
 * Factory.hpp
 *
 *  Created on: Feb 12, 2018
 *      Author: michal
 */

#ifndef INCLUDE_FACTORY_HPP_
#define INCLUDE_FACTORY_HPP_


#include "Ramp.hpp"
#include "Types.hpp"
#include "Worker.hpp"
#include "Storehouse.hpp"


#include <list>
#include <vector>
#include <algorithm>

class Factory {
private:
	std::list<Ramp> ramps;
	std::list<Worker> workers;
	std::list<Storehouse> storehouses;
public:
	// Ramp methods and iterators
	std::vector<Ramp> getRamp()const;
	void addRamp(Ramp _ramp){ramps.push_back(_ramp);}
	void removeRamp(ElementID _id);
	int getRampsNoumber()const{return ramps.size();}
	std::list<Ramp>::iterator findRampById(ElementID id){return std::find_if(ramps.begin(), ramps.end(),
		        [id](const Ramp& r){ return (r.getId() == id);});}
	std::list<Ramp>::iterator ramp_end(){return ramps.end();}
	std::list<Ramp>::const_iterator ramp_end()const{return ramps.end();}
	std::list<Ramp>::iterator ramp_begin(){return ramps.begin();}
	std::list<Ramp>::const_iterator ramp_begin()const{return ramps.begin();}


	//Storehouse methods and iterators
	std::vector<Storehouse>  getStorehouse()const;
	void addStorehouse(Storehouse _storehouse){storehouses.push_back(std::move(_storehouse));}
	void removeStorehouse(ElementID _id);
	int getStorehousesNoumber()const{return storehouses.size();}
	std::list<Storehouse>::iterator findStorehouseById(ElementID id){return std::find_if(storehouses.begin(), storehouses.end(),
	        [id](const Storehouse& s){ return (s.getID() == id);});}
	std::list<Storehouse>::iterator storehouse_end(){return storehouses.end();}
	std::list<Storehouse>::const_iterator storehouse_end()const{return storehouses.end();}
	std::list<Storehouse>::iterator storehouse_begin(){return storehouses.begin();}
	std::list<Storehouse>::const_iterator storehouse_begin()const{return storehouses.begin();}


	//Worker methods and iterators
	std::vector<Worker> getWorker()const;
	void addWorker(Worker _worker){workers.push_back(std::move(_worker));}
	void removeWorker(ElementID _id);
	int getWorkersNoumber()const{return workers.size();}
	std::list<Worker>::iterator findWorkerById(ElementID id){return std::find_if(workers.begin(), workers.end(),
	        [id](const Worker& w){ return (w.getID() == id);});}
	std::list<Worker>::iterator worker_end(){return workers.end();}
	std::list<Worker>::const_iterator worker_end()const{return workers.end();}
	std::list<Worker>::iterator worker_begin(){return workers.begin();}
	std::list<Worker>::const_iterator worker_begin()const{return workers.begin();}

	bool isConsistent()const;//TODO Methods examine loaded Factory

};

#endif /* INCLUDE_FACTORY_HPP_ */
