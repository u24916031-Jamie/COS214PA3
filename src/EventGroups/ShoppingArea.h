#ifndef SHOPPINGAREA_H
#define SHOPPINGAREA_H

#include "EventGroup.h"



/**
 *
 * @brief Shopping Area with Commercial Units
 *
 */
class ShoppingArea : public EventGroup {

public:
	/**
	 * @brief Constructor for ShoppingArea
	 * */
	ShoppingArea() : EventGroup() {};

	/**
 * @brief Destructor
 * */
	virtual ~ShoppingArea() {};

};

#endif
