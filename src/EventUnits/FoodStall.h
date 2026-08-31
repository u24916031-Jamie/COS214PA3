#ifndef FOODSTALL_H
#define FOODSTALL_H

#include "EventUnit.h"

class FoodStall : public EventUnit {

public:
	FoodStall() = delete;
	/**
	 * @brief Constructor for FoodStall
	 * */
	FoodStall(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~FoodStall() {};

};

#endif
