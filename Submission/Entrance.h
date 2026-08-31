#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "EventGroup.h"




/**
 *
 * @brief Entrance to Golf Tournament
 *
 */
class Entrance : public EventGroup {

public:
	/**
	 * @brief Constructor for Entrance
	 * */
	Entrance() : EventGroup() {};

	/**
 * @brief Destructor
 * */
	virtual ~Entrance() {};

	/**
	 * @brief Handles notifications
	 * @param notif Notification to be passed down to all children
	 * */
	void HandleNotification(Notifications notif)
	{
		EventGroup::HandleNotification(notif);
		if(notif==CAPACITYFULL)
		{
			status=PAUSED;
		}
	}
};

#endif
