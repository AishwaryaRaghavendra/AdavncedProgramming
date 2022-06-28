/*
 * CHeater.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CHEATER_H_
#define CHEATER_H_

#include "CActuator.h"
#include "CTempSensorTMP36.h"
#include "CPowerSupply.h"

/**< An Enumeration for the Heater block that denotes the ON and OFF condition */
typedef enum  {
	HEAT_ON,  /**< An enum Value to denote that Heater is ON */
	HEAT_OFF /**< An enum Value to denote that Heater is OFF */
} heaterState_t; /**< An enum Name to denote that Heater state */


/** CHeater class inherits the CActuator as public to access the methods of CActuator Base class
 * As part of the Feedback it aggregates the CTempSensorTMP36 class */
class CHeater : public CActuator{

public:
/**method heating() sets Heating when Heating Actuator is activated
 *@param myHeaterState is the enum value of the Heater
 *@param  firstTempSensor is the pointer instance of CTempSensorTMP36 class
 */
void heating(heaterState_t myHeaterState, CTempSensorTMP36* firstTempSensor);
};

#endif /* CHEATER_H_ */
