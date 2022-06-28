/*
 * CPowerSupply.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nisha
 */

#ifndef CPOWERSUPPLY_H_
#define CPOWERSUPPLY_H_

class CPowerSupply
{
private:
/** emergencyStop switch status is of type boolean. It is in False state during the process incase Load i.e the Heater or Cooler malfunctions then emergencyStop must set to True and the entire Process is stopped.*/
bool m_EmergencyStop;

public:
/** setter method declare_EmergencyStop() declares an Emergency Stop */
 void declare_EmergencyStop();
};

#endif /* CPOWERSUPPLY_H_ */
