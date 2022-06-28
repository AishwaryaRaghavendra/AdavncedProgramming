/*
 * CDisplayLCD.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CDISPLAYLCD_H_
#define CDISPLAYLCD_H_

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "CArduinoController.h"


/** Class CDisplayLCD inherits the CArduinoController base class to access the data members of it class for display    */
class CDisplayLCD : public CArduinoController
{
public:
	/**Constructor
	 *@param temp of type double is desired temperature input */
	CDisplayLCD(double temp);
	/** setter method print_Temperatures to display the desired temperature and Sensor Temperature.
	 * Additionally the Sensor output Voltage, the Controller Celsius Conversion output, the Power Supply status, Emergency Stop switch status also could be printed.*/

	/** to Display Temperatures */
	void print_Temperatures();
};

#endif /* CDISPLAYLCD_H_ */
