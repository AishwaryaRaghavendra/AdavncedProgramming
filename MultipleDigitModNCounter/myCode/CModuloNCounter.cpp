/*
 * CModuloNCounter.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: Aishwarya
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
#include <iomanip>
#include "CModuloNCounter.h"

/**  An Explicitly defined Default constructor to initialize the data members  */
CModuloNCounter::CModuloNCounter()
{
	// Initialize the member variables
	m_Curr_Count = 0;   /**< an integer data member m_Curr_Count to hold current count value of the Counter*/
	m_Max_Count =0;   /**< an integer data member m_Max_Count to hold maximum count value of the Counter */
}


/**  A Parameterized constructor
* @param max_Count a local unsigned int argument denotes the maximum count value of the Counter */
CModuloNCounter::CModuloNCounter( int max_Count)
{

	m_Max_Count = max_Count;
}


/** method calc_ModN_Counter to calculate the Counting operation of Modulo N Counter
	 * @return Overrun Flag of type  int
	 */
 int CModuloNCounter::calc_ModN_Counter()
{
	unsigned short int overrun_Flag = 0; /**< unsigned short int variable overrun_Flag to track the Overflow due to Counting */
	m_Curr_Count++;  /**< Start Counter */

	if (m_Curr_Count >= m_Max_Count)  /** Condition to check */
	{
		m_Curr_Count = 0;			 /** Yes, then set current count of counter to zero */
		overrun_Flag = 1;		/** Yes, reset Overrun flag to 1 */
	}

	return overrun_Flag;		/** return Overflow */
}


/** method display_Counter to display the Counting operation of Modulo N Counter
 * @param my_Counter_Property argument of type enum
 */
void CModuloNCounter::display_Counter(counter_property_t my_Counter_Property)
{

	if(COUNTER_VALUE == my_Counter_Property )  /** Condition to Print Counter value  */
	{
		if (m_Max_Count == 16)   /**  Incase of Hexadecimal  */
		{
			 cout << hex << uppercase << m_Curr_Count;  /** Display in Hexadecimal format   */
		}
		else
		{
			cout << m_Curr_Count;
		}
	}
	else
	 if(COUNTER_NAME == my_Counter_Property)  /** Condition to Print Counter Name   */

	{
		cout << m_Max_Count;
	}
}


/** Setter method set_Max_Count to set the maximum count value of the Counter
 * @param max_Count argument of type  int
 */
void CModuloNCounter::set_Max_Count( int max_Count)
{
	m_Max_Count = max_Count;
}


/** Getter method get_Max_Count to get the maximum count value of the Counter
 * @return Maximum count of the Counter of type  int
 */
 int CModuloNCounter::get_Max_Count()
{
	return m_Max_Count;
}


