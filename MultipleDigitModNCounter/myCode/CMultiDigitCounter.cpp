/*
 * CMultiDigitCounter.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: Aishwarya
 */
//Standard Library files
#include <iostream>
#include <stdlib.h>
#include <iomanip> // To display hexadecimal format of numbers
using namespace std;
#include "CMultiDigitCounter.h"


/**  A Parameterized constructor
 * @param digits an integer argument to hold no. of digits of Multidigit Counter
 * @param max_count an integer argument to hold maximum count value of the MultidigitCounter  */
CMultiDigitCounter::CMultiDigitCounter( int digits,  int max_count)
{	/**< no. of digits in the MultidigitCounter*/
	m_Digits = digits;

	/**< Maximum Count of the MultidigitCounter*/
	m_Max_count = max_count;

	/**< Mod N Counter Array dynamically allocated with size equal to no.of digits of MultidgitCounter*/
	m_ModN_Counter = new CModuloNCounter[digits];
}

/**  An Explicitly defined Default constructor to initialize the data members  */
CMultiDigitCounter::CMultiDigitCounter()
{
	m_Digits = 0;
	m_Max_count = 0;
}


/** method init_MultiDigit_Counter to setup the MultidigitCounter
 * checks for invalid digits and counter type entered
 * @return 1 incase the counter setup is as expected */
 int CMultiDigitCounter::init_MultiDigit_Counter()
{
	 int counterType_Check = 0; /**<  unsigned int variable counterType_Check to validate the Counter type and digits entered by the User */

	if((m_Max_count == 2) || (m_Max_count == 8) || (m_Max_count == 10) || (m_Max_count == 16)) /** checks for valid Counter Type */
	{
		counterType_Check = 1;	/** Valid Case */
	}

	if((m_Digits == 0) || (counterType_Check == 0)) 	/** Check for InValid input of digits and Counter Type */
	{
		cout << "End of the Test" << endl;  			/** Counting operation does Not take place */
		return 0;
	}

	for(  int i = 0; i<m_Digits; i++ ){  				/** Loop through the no.of digits */
		m_ModN_Counter[i].set_Max_Count(m_Max_count);  /** Setting the Counter Array with Max Count value for the MultidigitCounter to count  */
		m_ModN_Counter[i].display_Counter(COUNTER_VALUE);
		//	cout<<"MaxCount"<<i<<m_ModN_Counter[i].get_Max_Count()<<endl;

	}
	cout<<" ";

	return 1;
}


/**  A Destructor to deallocate the memory of the Mod N counter array  */
CMultiDigitCounter::~CMultiDigitCounter()
{
	delete [] m_ModN_Counter ;
}


/** method calc_MultiDigit_Counter to calculate the Counting operation of MultidigitCounter
 * @return Overrun Flag status of type unsigned int
 */
 int CMultiDigitCounter::calc_MultiDigit_Counter()
{
	unsigned int overrun_Flag = 1;  /**< unsigned int variable overrun_Flag to track the Overflow due to Counting */
	for( int i = 0; i < m_Digits; i++)  /** Loop through the no.of digits */
	{
		overrun_Flag = m_ModN_Counter[i].calc_ModN_Counter();  /** Calling the Calculate Logic of Modulo N Counter and assigning to the Overrun flag*/

		if(overrun_Flag == 0)
		{
			return 0;
		}
	}
	return 1;
}


/** method display_MultiDigit_Counter to display the Counting operation of MultidigitCounter by its Name and Digit and by its Counting Value
 * @return Overrun Flag status of type unsigned int
 */
void CMultiDigitCounter::display_MultiDigit_Counter(counter_property_t my_Counter_Property)
{
	if(COUNTER_VALUE == my_Counter_Property )  /** Enum Condition to Print MultidigitCounter value  */
	{
		for( int i = m_Digits-1; i>=0; i--)  /** Loop through the no.of digits */
			//for(int i =0; i<m_Digits; i++)
		{
			m_ModN_Counter[i].display_Counter(COUNTER_VALUE); /** Calling the Display Logic of Modulo N Counter for each of the digit */
		}

		cout<<" " ;
	}

	if(COUNTER_NAME == my_Counter_Property)  /** Enum Condition to Print MultidigitCounter by its Name and no. of Digits  */
	{
		m_ModN_Counter[0].set_Max_Count(m_Max_count);

		switch(m_ModN_Counter[0].get_Max_Count())  /** Checking the Max Count at the Counter of the array with switch case for defined Enum values*/
		{
		case BINARY: cout<< m_Digits << " digit Binary Counter"<< endl;
		break;
		case OCTAL: cout<< m_Digits << " digit Octal Counter"<< endl;
		break;
		case DECIMAL: cout<< m_Digits << " digit Decimal Counter"<< endl;
		break;
		case HEXADECIMAL: cout<< m_Digits << " digit Hexadecimal Counter"<< endl;
		break;
		}
	}

}


/**  Prefix Increment Operator Overloading */
CMultiDigitCounter& CMultiDigitCounter::operator ++()
{
	++m_ModN_Counter;
	return *this;

}

/** Postfix Increment Operator Overloading */
CMultiDigitCounter CMultiDigitCounter::operator ++(int int1)
{
	CMultiDigitCounter postfixInc = *this;
	m_ModN_Counter++;
	return postfixInc;


}






