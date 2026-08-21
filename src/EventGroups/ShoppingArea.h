#ifndef SHOPPINGAREA_H
#define SHOPPINGAREA_H

#include "EventGroup.h"

class ShoppingArea : public EventGroup {

public:
	ShoppingArea() = delete;
	/**
	 * @brief Constructor for ShoppingArea
	 * */
	ShoppingArea(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~ShoppingArea() {};

};

#endif
