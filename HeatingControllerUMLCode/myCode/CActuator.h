/*
 * CActuator.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CACTUATOR_H_
#define CACTUATOR_H_

/**< An Enumeration for the Actuator block that in turn controls Heater and Cooler */
typedef enum  {
	HEATER, /**< An enum Value to denote the heating Actuator */
	COOLER /**< An enum Value to denote the cooling Actuator */
} actuator_State_t; /**< An enum NAME to denote the Actuator state or type */

/** CActuator class block sets the Heater and Cooler modules accordingly based on the control signal from the CArudinoController block which calls either Heating or Cooling Actuator  */
class CActuator
{
public:
	/** Getter method activate_Heater
	*@param my_Actuator_State holds the enum value HEATER */
	void activate_Heater(actuator_State_t my_Actuator_State  );

	/** Getter method activate_Cooler
	*@param my_Actuator_State holds the enum value COOLER*/
	void  activate_Cooler(actuator_State_t my_Actuator_State );

};




#endif /* CACTUATOR_H_ */
