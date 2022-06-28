/*
 * CModuloNCounter.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Aishwarya
 */

#ifndef CMODULONCOUNTER_H_
#define CMODULONCOUNTER_H_

/**  An enumeration.
 * To print the Counter by its Value and Name
 */
typedef enum
{
	COUNTER_VALUE,    /**<  enum value COUNTER_VALUE. */
	COUNTER_NAME      /**<  enum value COUNTER_NAME. */
} counter_property_t; /**<  enum name. */

/** Class CModuloNCounter to perform Single digit Moduluo N(2,8,10,16) counting operation  */
class CModuloNCounter
{
private:

	 int m_Max_Count;   /**< an integer data member m_Max_Count to hold maximum count value of the Counter */
	 int m_Curr_Count;  /**< an integer data member m_Curr_Count to hold current count value of the Counter*/

public:

	/**  A Parameterized constructor
	 * @param max_Count an integer argument */
	CModuloNCounter( int max_Count);


	/**  An Explicitly defined Default constructor to initialize the data members  */
	CModuloNCounter();


	/** method calc_ModN_Counter to calculate the Counting operation of Modulo N Counter
	 * @return Overrun Flag of type int
	 */
	 int calc_ModN_Counter ();


	/** method display_Counter to display the Counting operation of Modulo N Counter
	 * @param my_Counter_Property argument of type enum
	 */
	void display_Counter(counter_property_t my_Counter_Property);


	/** Setter method set_Max_Count to set the maximum count value of the Counter
	 * @param max_Count argument of type int
	 */
	void set_Max_Count( int max_Count);


	/** Getter method get_Max_Count to get the maximum count value of the Counter
	 * @return Maximum count of the Counter of type int
	 */
	 int get_Max_Count();


};

#endif /* CMODULONCOUNTER_H_ */
