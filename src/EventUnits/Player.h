#ifndef PLAYER_H
#define PLAYER_H

#include "EventUnit.h"

class Player : public EventUnit {

public:
	Player() = delete;
	/**
	 * @brief Constructor for Player
	 * */
	Player(int capacity) : EventUnit(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~Player() {};

};

#endif
