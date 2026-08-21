#ifndef GREEN_H
#define GREEN_H

#include "EventGroup.h"

class Green : public EventGroup {

public:
	Green() = delete;
	/**
	 * @brief Constructor for Green
	 * */
	Green(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~Green() {};

};

#endif
