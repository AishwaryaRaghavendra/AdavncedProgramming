/*
 * CMultiDigitCounter.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Aishwarya
 */

#ifndef CMULTIDIGITCOUNTER_H_
#define CMULTIDIGITCOUNTER_H_
#include "CModuloNCounter.h"

/**  An enumeration.
 * To print the Counter by its Name(Type)
 */
typedef enum {
	BINARY=2, 		/**<  enum value BINARY. */
	OCTAL=8,  		/**<  enum value OCTAL. */
	DECIMAL=10,		/**<  enum value DECIMAL. */
	HEXADECIMAL=16	/**<  enum value HEXADECIMAL. */
} Counter_type_t;  /**<  enum name. */


/** Class CMultiDigitCounter to perform Multiple digits Moduluo N(2,8,10,16) counting operation  */
class CMultiDigitCounter
{
private:
	/**< an integer data member m_Digits to hold no. of Digits of the MultidigitCounter */
	 int m_Digits;

	 /**< an integer data member m_Max_Count to hold maximum count value of the MultidigitCounter */
	 int m_Max_count;

protected:
	/**Aggregation. CMultiDigitCounter Aggregates CModuloNCounter but CModuloNCounter can exist without CMultiDigitCounter.
	 * m_ModN_Counter is Array of Mod N Counters dynamically allocated with size of digits. It is of type CModuloNCounter */
	CModuloNCounter *m_ModN_Counter;

public:

	/**  A Parameterized constructor
	 * @param digits an integer argument to hold no. of digits of Multidigit Counter
	 * @param max_count an integer argument to hold maximum count value of the MultidigitCounter  */
	CMultiDigitCounter( int digits,  int max_count);


	/**  An Explicitly defined Default constructor to initialize the data members  */
	CMultiDigitCounter();

	/**  A Destructor to deallocate the memory of the ModN Counter array */
	virtual ~CMultiDigitCounter();


	/** method init_MultiDigit_Counter to setup the MultidigitCounter
	 * checks for invalid digits and counter type
	 * @return 1 incase the counter setup is as expected */
	 int init_MultiDigit_Counter();


	/** method calc_MultiDigit_Counter to calculate the Counting operation of MultidigitCounter
	 * @return Overrun Flag status of type int
	 */
	 int calc_MultiDigit_Counter();


	/** method display_Counter to display the Counting operation of MultidigitCounter
	 * @param my_Counter_Property argument of type enum
	 */
	void display_MultiDigit_Counter(counter_property_t my_Counter_Property);


	/**  method to perform Prefix Increment Operator Overloading
	 * @return of type CMultiDigitCounter
	 */
	CMultiDigitCounter& operator++();

	/** method to perform Postfix Increment Operator Overloading
		 * @return of type CMultiDigitCounter
		 */
	CMultiDigitCounter operator++(int );

};





#endif /* CMULTIDIGITCOUNTER_H_ */
