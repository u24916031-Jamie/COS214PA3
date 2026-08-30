#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "EventGroup.h"




/**
 *
 * @brief Entrance to Golf Tournament
 *
 */
class Entrance : public EventGroup {

public:
	/**
	 * @brief Constructor for Entrance
	 * */
	Entrance() : EventGroup() {};

	/**
 * @brief Destructor
 * */
	virtual ~Entrance() {};

};

#endif
