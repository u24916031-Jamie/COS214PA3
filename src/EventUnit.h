#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent {

public:
	/**
	 * @brief Constructor for EventUnit
	 * */
	EventUnit() : EventComponent(-1) {};


	/**
 * @brief Destructor
 * */
	virtual ~EventUnit() {};

};

#endif