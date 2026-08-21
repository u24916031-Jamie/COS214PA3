#ifndef SECURITYCHECKPOINT_H
#define SECURITYCHECKPOINT_H

#include "EventUnit.h"

class SecurityCheckpoint : public EventUnit {

public:
	SecurityCheckpoint() = delete;
	/**
	 * @brief Constructor for SecurityCheckpoint
	 * */
	SecurityCheckpoint(int capacity) : EventUnit(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~SecurityCheckpoint() {};

};

#endif
