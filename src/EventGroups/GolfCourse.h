#ifndef GOLFCOURSE_H
#define GOLFCOURSE_H

#include "EventGroup.h"

class GolfCourse : public EventGroup {

public:
	GolfCourse() = delete;
	/**
	 * @brief Constructor for GolfCourse
	 * */
	GolfCourse(int capacity) : EventGroup(capacity) {};

	/**
 * @brief Destructor
 * */
	virtual ~GolfCourse() {};

};

#endif
