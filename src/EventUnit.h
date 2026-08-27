#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent {

public:
	EventUnit() = delete;
	/**
	 * @brief Constructor for EventUnit
	 * */
	EventUnit(int capacity) : EventComponent(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~EventUnit() {};


	virtual void HandleNotification(Notifications notif) {
		// do nothing
	}
};

#endif