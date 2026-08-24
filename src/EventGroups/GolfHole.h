#ifndef GOLFHOLE_H
#define GOLFHOLE_H

#include "EventGroup.h"

class GolfHole : public EventGroup {

public:
	GolfHole() = delete;
	/**
	 * @brief Constructor for GolfHole
	 * */
	GolfHole(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~GolfHole() {};

};

#endif
