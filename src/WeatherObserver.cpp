#include "WeatherObserver.h"
#include "WeatherMeter.h"

void WeatherObserver::update()
{
	if (subject == nullptr)
	{
		return;
	}
	weather = subject->getState();
	if (root == nullptr)
	{
		return;
	}
	if (weather == THUNDER)
	{
		root->HandleNotification(PAUSE);
	}
	else if (weather == CLEAR)
	{
		root->HandleNotification(RESUME);
	}
}
