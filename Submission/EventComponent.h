#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H
enum EventStatus {
	OPENED, CLOSED, PAUSED
};
#include <string>
#include "Notifications.h"
class PlayerTent;
/**
 *
 * @brief Component class of Composite Design pattern
 *
 */
class EventComponent {
protected:
	EventComponent() {};
protected:

	EventStatus status = CLOSED;


public:

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
* @brief Gets current status
* @param status new status of component
*/
	virtual void setStatus(EventStatus status) {
		this->status = status;
	}
	/**
* @brief Gets current capacity
* @return int current capacity  of component
*/
	virtual int getCapacity()const = 0;

	/**
	 * @brief Gets current number of people in component
	 * @return int current number of people in component
	 * */
	virtual int getSize() const = 0;

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

	/**
	 * @brief Handles notifications
	 * @param notif Notification to be passed down to all children
	 * */
	virtual void HandleNotification(Notifications notif) 
	{
		if(notif==Notifications::OPEN)
		{
			status=OPENED;
		}
		else if(notif==Notifications::CLOSE)
		{
			status=CLOSED;
		}
		else if(notif==Notifications::PAUSE)
		{
			status=PAUSED;
		}
		else if(notif==Notifications::RESUME)
		{
			status=OPENED;
		}
	};
	/**
 * @brief Sets player tent for all golf holes
 * @param tent weak tent pointer to be passed to holes
 * */
	virtual void SetPlayerTent(PlayerTent* ) {};

};
#endif