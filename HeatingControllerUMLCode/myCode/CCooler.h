/*
 * CCooler.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CCOOLER_H_
#define CCOOLER_H_

#include "CActuator.h"
#include "CTempSensorTMP36.h"
#include "CPowerSupply.h"

/**< An Enumeration for the Cooler block that denotes the ON and OFF condition */
typedef enum {
	COOLER_ON,  /**< An enum Value to denote that Cooler is ON */
	COOLER_OFF  /**< An enum Value to denote that Cooler is OFF */
} coolerState_t; /**< An enum Name to denote that Cooler state */

/** CCooler class inherits the CActuator as public to access the methods of CActuator Base class  */
class CCooler : public CActuator{

public:
 /** setter method cooling() sets cooling when cooling Actuator is activated
 *@param myHeaterState is the enum value of the Cooler
 *@param  firstTempSensor is the pointer instance of CTempSensorTMP36 class */
	void cooling(coolerState_t myCoolerState, CTempSensorTMP36* secondTempSensor);
};

#endif /* CCOOLER_H_ */
