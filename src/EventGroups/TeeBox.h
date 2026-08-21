#ifndef TEEBOX_H
#define TEEBOX_H

#include "EventGroup.h"

class TeeBox : public EventGroup {

public:
	TeeBox() = delete;
	/**
	 * @brief Constructor for TeeBox
	 * */
	TeeBox(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~TeeBox() {};

};

#endif
