#ifndef FAIRWAY_H
#define FAIRWAY_H

#include "EventGroup.h"

class Fairway : public EventGroup {

public:
	Fairway() = delete;
	/**
	 * @brief Constructor for Fairway
	 * */
	Fairway(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~Fairway() {};

};

#endif
