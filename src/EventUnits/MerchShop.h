#ifndef MERCHSHOP_H
#define MERCHSHOP_H

#include "EventUnit.h"

class MerchShop : public EventUnit {

public:
	MerchShop() = delete;
	/**
	 * @brief Constructor for MerchShop
	 * */
	MerchShop(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~MerchShop() {};

};

#endif
