#ifndef WEATHERMETER_H
#define WEATHERMETER_H

#include "EventUnit.h"
#include "Subject.h"
#include "Observer.h"
#include <string>
#include <vector>
#include "WeatherObserver.h"
#include "Notifications.h"


class WeatherMeter : public EventUnit, public Subject {

private:
	Notifications weather = CLEAR;
	std::vector<Observer*> observerList;


public:
	WeatherMeter() = delete;
	/**
	 * @brief Constructor for WeatherMeter
	 * */
	WeatherMeter(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~WeatherMeter() {};


	void attach(WeatherObserver* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
		observer->registerWeatherMeter(this);

	}


	void detach(WeatherObserver* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				std::vector<Observer*>::iterator it;
				it += i;
				observer->deregisterWeatherMeter();
				observerList.erase(it);
				return;
			}
		}
	}

	void setWeather(Notifications weather) {
		switch (weather) {
		case (CLEAR):
		case(RAIN):
		case(THUNDER):
			this->weather = weather;
			break;

		default:
			return;

		}
		notify();
	}

	Notifications getState() {
		return weather;
	}

};

#endif
