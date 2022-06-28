/*
 * CCooler.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CCooler.h"

/**< When Cooler is ON the temperature measured by Sensor is decreased in steps of 0.5 Celsius until the desired temperature is reached */
#define TEMP_DIFF 0.5

/*  First checks for the Power supply is ON
 * setter method cooling starts cooling when cooling Actuator is activated
 * In feedback, it sets the sensor method to update the temperature measured in steps of 0.5 Celsius until the desired temperature is reached and then Cooler is OFF
 *@param myHeaterState is the enum value of the Cooler
 *@param  firstTempSensor is the pointer instance of CTempSensorTMP36 class
 */
void CCooler::cooling(coolerState_t myCoolerState, CTempSensorTMP36 *secondTempSensor)
{

}

