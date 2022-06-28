/*
 * CArduinoController.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CARDUINOCONTROLLER_H_
#define CARDUINOCONTROLLER_H_

#include "CActuator.h"
#include "CTempSensorTMP36.h"
#include "CPowerSupply.h"
#define POWER_SUPPLY ON // Setting the POWER_SUPPLY macro to ON to kickstart the Process


/** Class CArduinoController employs Arduino Board as the Controller Unit for the Process.
 * Power Supply is ON for it to function else the Controller is in OFF state
 * Performs the Analog to Digit Conversion of the Voltage received from the Sensor.
 * Performs degrees Celsius Conversion.
 * Executes the Comparator Logic that is to check the difference between the Sensor Temperature and desired(User Input)temperature
   where the error signal = UserTemp - SensorTemp(Feedback)
 * If the error signal >0, Heater Turn ON and if error signal <0,Cooler Turn ON.
 * Sets the appropriate Relay Drivers ON of either Heater or Cooler depending on the Comparator Logic */
class CArduinoController
{
private:
	/**< Desired Temperature to achieve of type double. */
	double m_userTemp;

	/**< degrees Celsius Conversion is stored in this variable of type double. */
	double m_celsius_Temp;

	/**< ADC output is stored in this variable of type double. */
	double m_ADC_Volt;

	/**< Aggregation. CArduinoController aggregates CTempSensorTMP36 to get the sensor voltage equivalent to sensed Temperature for the Heater Load*/
	CTempSensorTMP36* m_FirstTempSensor;

	/**< Aggregation. CArduinoController aggregates CTempSensorTMP36 to get the sensor voltage equivalent to sensed Temperature for the Cooler Load */
	CTempSensorTMP36* m_SecondTempSensor;

	/**< Aggregation. CArduinoController aggregates CActuator. It sets the Actuator Unit by sending the control signal. */
	CActuator* m_Actuator;

	/**< bool data member m_EmergStop to denote the Emergency stop status  */
	bool m_EmergStop;

public:
	/** A parameterized Constructor
	 *@param desiredTemp of type double   */
	CArduinoController(double desiredTemp);


	/** An explicit default Constructor to initialize data members */
	CArduinoController();

	/** A Destructor to destroy the memory allocated to the data members */
	virtual ~CArduinoController();


	/** method analog_to_Digital_Conv
	 *@param sensor_Volt of type double
	 *@return ADC output Volt of type double.
	 */
	double analog_to_Digital_Conv(double sensor_Volt);


	/** method celsius_Conv
	 *@return m_celcius_Temp is the Temperature in Celsius of type double */
	double celsius_Conv();


	/** method logic_Comparator checks the difference between the Sensor Temperature and desired(User Input)temperature.
	 */
	void logic_Comparator();

	/** method get_EmergencyStopStatus() of type Bool returns the Emergency Stop Status TRUE */
	bool get_EmergencyStopStatus();
};

#endif /* CARDUINOCONTROLLER_H_ */
