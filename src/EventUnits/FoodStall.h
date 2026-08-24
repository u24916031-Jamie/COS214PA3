#ifndef FOODSTALL_H
#define FOODSTALL_H

#include "EventUnit.h"

class FoodStall : public EventUnit {

public:
	FoodStall() = delete;
	/**
	 * @brief Constructor for FoodStall
	 * */
	FoodStall(int capacity) : EventUnit(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~FoodStall() {};

};

#endif
