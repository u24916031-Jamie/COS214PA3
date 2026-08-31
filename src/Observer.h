#ifndef OBSERVER_H
#define OBSERVER_H


/**
 *
 * @brief Base Observer of Observer Design pattern
 *
 */
class Observer {

public:
	virtual void update() = 0;

	virtual ~Observer() {};
};

#endif
