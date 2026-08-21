#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "EventGroup.h"

class Entrance : public EventGroup {

public:
	Entrance() = delete;
	/**
	 * @brief Constructor for Entrance
	 * */
	Entrance(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~Entrance() {};

};

#endif
