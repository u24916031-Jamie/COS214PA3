#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

enum EventUnitType {
	GolfHoleUnit, Other
};


class EventUnit : public EventComponent {
private:
	EventUnitType type;
public:
	EventUnit() = delete;
	/**
	 * @brief Constructor for EventUnit
	 * */
	EventUnit(int capacity, EventUnitType type) : EventComponent(capacity) {
		this->type = type;
	};

	/**
 * @brief Destructor
 * */
	virtual ~EventUnit() {};


	virtual void HandleNotification(Notifications notif) {
		// do nothing
	}
};

#endif