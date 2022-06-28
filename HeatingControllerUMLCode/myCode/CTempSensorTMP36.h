/*
 * CTempSensorTMP36.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CTEMPSENSORTMP36_H_
#define CTEMPSENSORTMP36_H_

/**< for programming we dont have Real Time Sensor to provide Initial Temperature.
 * So Macro used to set an arbitary INTIAL_TEMPERATURE sensed by the Sensor */
#define INTIAL_TEMPERATURE 15

/**< An Enumeration to denote the actual sensed states by the Sensor */
typedef enum {
	HEAT,  /**< An enum Value to denote the Heat/warm state */
	COOL 	/**< An enum Value to denote the Cool/cold state */
} state_t; /**< An enum Name */


/** Class CTempSensorTMP36 employs TMP36 Temperature Sensor. Sensor measures the initial temperature of the system in Celsius
 *  and later outputs the equivalent analog voltage.  */
class CTempSensorTMP36
{
protected:
	 /**< double data member m_Max_Count to denote Sensor Temperature */
	double m_Sensor_Temp;
	/**< double data member m_Max_Count to denote Analog Output Voltage equivalent to the Sensed Temperature  */
	double m_Sensor_Volt;

public:

	/** A Parameterized Constructor CTempSensorTMP36
	 * @param  currTemp of type double denotes the current temperature in Celsius that is continuously being measured by the sensor */
	CTempSensorTMP36(double currTemp);

	/** A Destructor should deallocate the memory */
	virtual ~CTempSensorTMP36();

	/** A Setter method to keep sensing the temperature difference and and updating it in incremental or decremental fashion with respected to desired temperature
	 * @param temp_diff denotes the difference in temperature that the sensor updates based on feedback state values from Heater and Cooler
	 * @param enum state denotes enum values HEAT and COOL which are feedback state values from Heater and Cooler*/
	void set_Sensor_Temp(double temp_diff, state_t myState) ;

	/** A getter method get_SensorTemp_to_Voltage
	* @return m_Sensor_Volt of type double denotes the Analog Output Voltage equivalent to the Sensed Temperature which is then fed to the Controller  */

	double get_SensorTemp_to_Voltage();
};

#endif /* CTEMPSENSORTMP36_H_ */
