/*
 * CHeater.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CHeater.h"

#define TEMP_DIFF 0.5 /**< When Heater is ON the temperature measured by Sensor is increased in steps of 0.5 Celsius until the desired temperature is reached */


/*  First checks for the Power supply is ON
 * setter method heating sets Heating when Heating Actuator is activated
 * In feedback, it sets the sensor method to update the temperature measured in steps of 0.5 Celsius until the desired temperature is reached and then Heater is OFF
 *@param myHeaterState is the enum value of the Heater
 *@param  firstTempSensor is the pointer instance of CTempSensorTMP36 class
 * If the Heater turns faulty and overheats, then the emergencyStop global member must to set true to stop the heating process
 */
void CHeater::heating(heaterState_t myHeaterState, CTempSensorTMP36* firstTempSensor )
{

}
