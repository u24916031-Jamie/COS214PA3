#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

enum EventUnitType {
	GolfHoleUnit, Other
};


class EventUnit : public EventComponent {
private:
	EventUnitType type;
	int capacity = 0;
	int size = 0;
public:
	EventUnit() = delete;
	/**
	 * @brief Constructor for EventUnit
	 * */
	EventUnit(int capacity, EventUnitType type) : EventComponent(), capacity(capacity), type(type) {};

	/**
 * @brief Destructor
 * */
	virtual ~EventUnit() {};
	virtual int getCapacity()const {
		return capacity;
	}


	virtual int getSize() const {
		return size;
	}

	virtual void HandleNotification(Notifications notif) {
		// do nothing
	}

	virtual void open() {
		status = EventStatus::OPENED;
	};

	virtual void close() {
		status = EventStatus::CLOSED;

	};

	virtual void addComponent(EventComponent* component) {};

	virtual void removeComponent(EventComponent* component) {};
};


#endif