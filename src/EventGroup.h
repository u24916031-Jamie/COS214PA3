#ifndef EVENTGROUP_H
#define EVENTGROUP_H


#include "EventComponent.h"
#include <vector>



/**
 *
 * @brief Composite class of Composite Design pattern
 *
 */
class EventGroup : public EventComponent {


private:
	std::vector<EventComponent*> children = {};

public:
	EventGroup() : EventComponent() {};


	/**
		*@brief Gets current capacity
			* @return int current capacity  of component
			*/
	virtual int getCapacity()const {
		int capacity = 0;
		for (auto child : children) {
			capacity += child->getCapacity();
		}
		return capacity;
	}

	/**
	 * @brief Gets current number of people in component
	 * @return int current number of people in component
	 * */
	virtual int getSize() const {
		int size = 0;
		for (auto child : children) {
			size += child->getSize();
		}
		return size;
	}

	/**
 * @brief handles OPEN order
 */
	virtual void open() {
		for (auto child : children) {
			child->open();
		}
	}
	/**
 * @brief handles CLOSE order
 */
	virtual void close() {
		for (auto child : children) {
			child->close();
		}
	}
	/**
		 * @brief Adds a component as a child
		 * @param component pointer to new EventComponent
		 * */
	void addComponent(EventComponent* component) {
		std::vector<EventComponent*>::iterator it;

		for (it = children.begin();it != children.end();it++) {
			if (*it == component) {
				return;
			}
		}
		children.push_back(component);
	};

	/**
		 * @brief Removes componenet as child
		 * @param component component to remove
		 * */
	void removeComponent(EventComponent* component) {
		std::vector<EventComponent*>::iterator it;

		for (it = children.begin();it != children.end();it++) {
			if (*it == component) {
				children.erase(it);
				return;
			}
		}
	}

	/**
	 * @brief Destructor
	 * */
	virtual ~EventGroup() {
		for (auto child : children) {
			delete child;
		}
	};

	/**
		 * @brief Handles notifications
		 * @param notif Notification to be passed down to all children
		 * */
	virtual void HandleNotification(Notifications notif) {
		for (auto child : children) {
			child->HandleNotification(notif);
		}
	}

	/**
* @brief Sets player tent for all golf holes
* @param tent weak tent pointer to be passed to holes
* */
	virtual void SetPlayerTent(PlayerTent* tent) {
		for (auto child : children) {
			child->SetPlayerTent(tent);
		}
	}


};


#endif
