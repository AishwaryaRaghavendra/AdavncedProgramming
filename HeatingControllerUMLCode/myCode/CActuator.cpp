/*
 * CActuator.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CActuator.h"

/** Setter method activate_Heater is used to set the Heater ON when the temperature measured is less than the desired temperature
*@param my_Actuator_State holds the enum value HEATER that is being set from the CArudinoController block when the temperature measured is less than the desired temperature
*/
void CActuator::activate_Heater(actuator_State_t my_Actuator_State)
{

}

/** Setter method activate_Cooler is used to set the COOLER ON when the temperature measured is greater than the desired temperature
*@param my_Actuator_State holds the enum value COOLER that is being set from the CArudinoController block when the temperature measured is greater than the desired temperature
*/
void CActuator::activate_Cooler(actuator_State_t my_Actuator_State)
{

}
