#ifndef EVENTGROUP_H
#define EVENTGROUP_H


#include "EventComponent.h"
#include <vector>




class EventGroup : public EventComponent {


private:
	std::vector<EventComponent*> children = {};

public:
	EventGroup() : EventComponent() {};

	virtual int getCapacity()const {
		int capacity = 0;
		for (auto child : children) {
			capacity += child->getCapacity();
		}
	}

	virtual int getSize() const {
		int size = 0;
		for (auto child : children) {
			size += child->getSize();
		}
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

	virtual void HandleNotification(Notifications notif) {
		for (auto child : children) {
			child->HandleNotification(notif);
		}
	}
	virtual void SetPlayerTent(PlayerTent* tent) {
		for (auto child : children) {
			child->SetPlayerTent(tent);
		}
	}


};


#endif
