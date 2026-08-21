#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "EventUnit.h"

class Scoreboard : public EventUnit {

public:
	Scoreboard() = delete;
	/**
	 * @brief Constructor for Scoreboard
	 * */
	Scoreboard(int capacity) : EventUnit(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~Scoreboard() {};

};

#endif
