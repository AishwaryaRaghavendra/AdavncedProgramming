/*
 * CArduinoController.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CArduinoController.h"


/** An explicit default Constructor to initialize data members
 * Initializes its Ports when the POWER SUPPLY is ON set by the Macro here. */
CArduinoController::CArduinoController()
{
	// TODO
}

/** A parameterized Constructor
 *@param desiredTemp of type double refers to the user desired Temperature to achieve
 */
CArduinoController::CArduinoController(double desiredTemp)
{
	// TODO
}

/** A Destructor to destroy the memory allocated to the data members */
CArduinoController::~CArduinoController()
{
	// TODO Auto-generated destructor stub
}

/** method analog_to_Digital_Conv performs 10 Bit Analog to Digital Conversion (ADC).
 *@param sensor_Volt of type double is the Analog Voltage output from Sensor Module.
 *@return ADC output Volt of type double. The data in its bits is converted to mV i.e 0 corresponds to 0 V and an output of 1023 corresponds to 5 V.
 *i.e Voltage is linearly proportional to the Temperature.
 */
double CArduinoController::analog_to_Digital_Conv(double sensor_Volt)
{
	return m_ADC_Volt;
}


/** method celsius_Conv converts ADC output volt to equivalent temperature in degrees Celsius based on the datasheet of the TMP36 Temperature Sensor
 *@return m_celcius_Temp is the Temperature in Celsius of type double */
double CArduinoController::celsius_Conv()
{
	return m_celsius_Temp;
}

/** method logic_Comparator checks the difference between the Sensor Temperature and desired(User Input)temperature.
 * This method triggers the either Heating Actuator or Cooling Actuator
 * If the actual sensed Temperature < Desired Temperature, then Heating Actuator is activated
 * else, if actual sensed Temperature > Desired Temperature, then Cooling Actuator is activated
 */
void CArduinoController::logic_Comparator()
{
	// TODO
}


/** method get_EmergencyStopStatus() of type Bool returns the Emergency Stop Status TRUE when logic_Comparator() finds the Actuator not doing its job
 *Incase of Overheating or Overcooling or any Safety Failure Emergency Status is returned true  */
bool CArduinoController::get_EmergencyStopStatus()
{
	return m_EmergStop;
}

