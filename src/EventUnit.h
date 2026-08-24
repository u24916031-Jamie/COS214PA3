<<<<<<< HEAD
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

};

=======
#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent {

public:
	/**
	 * @brief Constructor for EventUnit
	 * */
	EventUnit() : EventComponent(-1) {};


	/**
 * @brief Destructor
 * */
	virtual ~EventUnit() {};

};

>>>>>>> c2d23ac334d0c772464a3bf9e8cba813e4948914
#endif