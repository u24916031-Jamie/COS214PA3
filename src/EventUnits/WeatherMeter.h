#ifndef WEATHERMETER_H
#define WEATHERMETER_H

#include "EventUnit.h"

class WeatherMeter : public EventUnit {

public:
	WeatherMeter() = delete;
	/**
	 * @brief Constructor for WeatherMeter
	 * */
	WeatherMeter(int capacity) : EventUnit(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~WeatherMeter() {};

};

#endif
