#ifndef WEATHEROBSERVER_H
#define WEATHEROBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <vector>
#include "EventComponent.h"

class WeatherMeter;


/**
 *
 * @brief Acts as observer to WeatherMeter
 *
 */
class WeatherObserver : public Observer {
protected:
	Notifications weather;

	WeatherMeter* subject;

	EventComponent* root = nullptr;


public:


	virtual ~WeatherObserver() {

	}

	void registerWeatherMeter(WeatherMeter* weatherMeter) {
		subject = weatherMeter;
	}
	void deregisterWeatherMeter() {
		subject = nullptr;
	}



	void setRoot(EventComponent* root)
	{
		this->root = root;
	}

	void update();



};

#endif
