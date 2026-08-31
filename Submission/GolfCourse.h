#ifndef GOLFCOURSE_H
#define GOLFCOURSE_H

#include "EventGroup.h"
#include "PlayerTent.h"


/**
 *
 * @brief Golf Course
 *
 */
class GolfCourse : public EventGroup {

public:
	/**
	 * @brief Constructor for GolfCourse
	 * */
	GolfCourse() : EventGroup() {};

	/**
	 * @brief Handles notifications
	 * @param notif Notification to be passed down to all children
	 * */
	void HandleNotification(Notifications notif)
	{
		EventGroup::HandleNotification(notif);
		if(notif==THUNDER)
		{
			status=CLOSED;
		}
		if(notif==CLEAR)
		{
			status=OPENED;
		}
	}


	/**
 * @brief Destructor
 * */
	virtual ~GolfCourse() {};

};

#endif
