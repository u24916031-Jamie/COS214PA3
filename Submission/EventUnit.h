#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

enum EventUnitType {
	GolfHoleUnit, Other
};

/**
 *
 * @brief Leaf class of Composite Design pattern
 *
 */
class EventUnit : public EventComponent {
private:
	int capacity = 0;
	EventUnitType type;
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


	/**
	 * @brief Gets current number of people in component
	 * @return int current number of people in component
	 * */
	virtual int getSize() const {
		return size;
	}
	/**
		 * @brief Handles notifications
		 * @param notif Notification to be passed down to all children
		 * */
	virtual void HandleNotification(Notifications notif) {
		EventComponent::HandleNotification(notif);
	}

	/**
 * @brief handles OPEN order
 */
	virtual void open() {
		status = EventStatus::OPENED;
	};

	/**
 * @brief handles CLOSE order
 */
	virtual void close() {
		status = EventStatus::CLOSED;

	};
	/**
			 * @brief Adds a component as a child. Does nothing as EventUnit
			 * @param component pointer to new EventComponent
			 * */
	virtual void addComponent(EventComponent* ) {};
	/**
			 * @brief Removes a component as a child. Does nothing as EventUnit
			 * @param component pointer to EventComponent
			 * */
	virtual void removeComponent(EventComponent* ) {};
};


#endif