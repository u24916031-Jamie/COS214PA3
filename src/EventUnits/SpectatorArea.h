#ifndef SPECTATORAREA_H
#define SPECTATORAREA_H

#include "EventUnit.h"

class SpectatorArea : public EventUnit {

public:
	SpectatorArea() = delete;
	/**
	 * @brief Constructor for WeatherMeter
	 * */
	SpectatorArea(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~SpectatorArea() {};

};

#endif
