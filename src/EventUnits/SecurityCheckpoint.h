#ifndef SECURITYCHECKPOINT_H
#define SECURITYCHECKPOINT_H

#include "EventUnit.h"


/**
	* @brief Security Checkpoint where spectators are cleared for entry
	*/
class SecurityCheckpoint : public EventUnit {

public:
	SecurityCheckpoint() = delete;
	/**
	 * @brief Constructor for SecurityCheckpoint
	 * */
	SecurityCheckpoint(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~SecurityCheckpoint() {};

};

#endif
