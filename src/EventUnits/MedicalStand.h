#ifndef MEDICALSTAND_H
#define MEDICALSTAND_H

#include "EventUnit.h"

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
