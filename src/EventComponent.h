#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H
enum EventStatus {
	OPEN, CLOSED, PAUSED
};
#include <string>
#include "Notifications.h"
/**
 *
 * @brief Component class of Composite Design pattern
 *
 */
class EventComponent {
protected:
	EventComponent(int capacity) : capacity(capacity) {};
private:

	EventStatus status = CLOSED;
	int capacity;
	int size;

public:
	EventComponent() = delete;

	/**
	 * @brief handles OPEN order
	 */
	virtual void open() = 0;
	/**
 * @brief handles CLOSE order
 */
	virtual void close() = 0;
	/**
* @brief Gets current status
* @return current status of component
*/
	virtual EventStatus reportStatus() const {
		return status;
	}
	/**
* @brief Gets current capacity
* @return int current capacity  of component
*/
	virtual int getCapacity()const {
		return capacity;
	}

	/**
	 * @brief Gets current unmber of people in component
	 * @return int current unmber of people in component
	 * */
	virtual int getSize() const {
		return size;
	}

	/**
		 * @brief Adds a component as a child
		 * @param component pointer to new EventComponent
		 * */
	virtual void addComponent(EventComponent* component) = 0;

	/**
	 * @brief Removes componenet as child
	 * @param component component to remove
	 * */
	virtual void removeComponent(EventComponent* component) = 0;
	/**
	 * @brief Destructor
	 * */
	virtual ~EventComponent() {};


	virtual void HandleNotification(Notifications notif) = 0;
};
#endif