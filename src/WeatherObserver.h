#ifndef WEATHEROBSERVER_H
#define WEATHEROBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <vector>
#include "WeatherMeter.h"


/**
 *
 * @brief Acts as observer to WeatherMeter
 *
 */
class WeatherObserver : public Observer {
protected:
	Notifications weather;

	WeatherMeter* subject;


public:


	virtual ~WeatherObserver() {

	}

	void registerWeatherMeter(WeatherMeter* weatherMeter) {
		subject = weatherMeter;
	}
	void deregisterWeatherMeter() {
		subject = nullptr;
	}




	void update() {
		weather = subject->getState();
	}



};

#endif