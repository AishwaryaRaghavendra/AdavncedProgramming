/*
 * CDisplayLCD.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#include "CDisplayLCD.h"

/** Class CDisplayLCD inherits the CArduinoController base class to access the data members of it class for display    */
CDisplayLCD::CDisplayLCD(double temp) : CArduinoController(temp)
{
	// TODO Auto-generated constructor stub

}

/** method print_Temperatures() prints the Sensor Temperature, User Temperature,
 *  Sensor Output Voltage, ADC output and Celsius Conversion output  */
void CDisplayLCD::print_Temperatures()
{
}

