/*
 * Types.hpp
 *
 *  Created on: Jan 26, 2018
 *      Author: michal
 */

#ifndef TYPES_HPP_
#define TYPES_HPP_

typedef int ElementID;
typedef int Time;
typedef int TimeOffset;

enum class QueueType {
	LIFO, FIFO
};

enum class ReceiverType {
	WORKER, STOREHOUSE
};

#endif /* TYPES_HPP_ */
