#ifndef MEDICALSTAND_H
#define MEDICALSTAND_H

#include "EventUnit.h"


/**
* @brief Medical Stand for medical emergencies
*/
class MedicalStand : public EventUnit {

public:
	MedicalStand() = delete;
	/**
	 * @brief Constructor for MedicalStand
	 * */
	MedicalStand(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~MedicalStand() {};

};

#endif
