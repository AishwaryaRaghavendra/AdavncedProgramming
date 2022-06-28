/*
 * CTempSensorTMP36.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CTempSensorTMP36.h"

/** A Parameterized Constructor CTempSensorTMP36
* @param  currTemp of type double denotes the current temperature in Celsius that is continuously being measured by the sensor */
CTempSensorTMP36::CTempSensorTMP36(double currTemp = INTIAL_TEMPERATURE )
{
	// TODO Auto-generated constructor stub
	 m_Sensor_Temp = currTemp;

};

/** A Destructor should deallocate the memory */
CTempSensorTMP36::~CTempSensorTMP36()
{
	// TODO Auto-generated destructor stub
	m_Sensor_Volt=0;
}

/** A Setter method to keep sensing the temperature difference and and updating it in incremental or decremental fashion with respected to desired temperature
 * @param temp_diff denotes the difference in temperature that the sensor updates based on feedback state values from Heater and Cooler
 * @param enum state denotes enum values HEAT and COOL which are feedback state values from Heater and Cooler*/
void CTempSensorTMP36::set_Sensor_Temp(double temp_diff, state_t myState)
{

}

/** A getter method get_SensorTemp_to_Voltage
* @return m_Sensor_Volt of type double denotes the Analog Output Voltage equivalent to the Sensed Temperature which is then fed to the Controller  */
double CTempSensorTMP36::get_SensorTemp_to_Voltage()
{
	return m_Sensor_Volt;
}
