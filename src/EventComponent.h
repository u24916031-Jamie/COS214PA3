#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
/**
 *
 * @brief Component class of Composite Design pattern
 *
 */
class EventComponent {
protected:
	EventComponent(int capacity) : capacity(capacity) {};
private:

	std::string status = "closed";
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
	virtual std::string reportStatus() const {
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
};

#endif