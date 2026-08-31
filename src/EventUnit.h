#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

enum EventUnitType {
	GolfHoleUnit, Other
};


class EventUnit : public EventComponent {
private:
	int capacity = 0;	
	EventUnitType type;
	int size=0;
public:
	EventUnit() = delete;
	/**
	* @brief Constructor for EventUnit
	**/
	EventUnit(int capacity, EventUnitType type) : EventComponent(), capacity(capacity), type(type) {};

	/**
	* @brief Destructor
	**/
	virtual ~EventUnit() {};
	virtual int getCapacity()const {
		return capacity;
	}


	virtual int getSize() const {
		return size;
	}
	/**
	 * @brief Does nothing
	 */
	virtual void HandleNotification(Notifications) {}
	/**
	 * @brief Sets status to opened
	 */
	virtual void open() {
		status = EventStatus::OPENED;
	};

	/**
	 * @brief Sets status to closed
	 */
	virtual void close() {
		status = EventStatus::CLOSED;

	};
	/**
	 * @brief Adds the component if possible
	 */
	virtual void addComponent(EventComponent*) {};
	/**
	 * @brief Removes component if possible
	 */
	virtual void removeComponent(EventComponent*) {};
};


#endif