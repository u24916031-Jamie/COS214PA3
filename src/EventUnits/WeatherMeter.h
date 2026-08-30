#ifndef WEATHERMETER_H
#define WEATHERMETER_H

#include "EventUnit.h"
#include "Subject.h"
#include "Observer.h"
#include <string>
#include <vector>
#include "WeatherObserver.h"
#include "Notifications.h"



/**
	* @brief Senses the current state of the weather
	*/
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


	/**
		* @brief Attaches WeatherObserver as observer
		*@param observer Weak pointer to WeatherObserver object
		*/
	void attach(WeatherObserver* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
		observer->registerWeatherMeter(this);

	}


	/**
		* @brief Detaches WeatherObserver as observer
		* @param observer Weak pointer to WeatherObserver to be removed as observer
		*/
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
	/**
		* @brief Sets the current weather
		* @param weather Weather status
		*/
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
	/**
		* @brief Gets the current state of the weather
		*/
	Notifications getState() {
		return weather;
	}

};

#endif
