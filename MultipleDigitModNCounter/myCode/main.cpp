// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#include "CModuloNCounter.h"
#include "CMultiDigitCounter.h"


// Main program
int main(void)
{
	 int no_Of_Digits = 0;   /**< an integer variable no_Of_Digits to hold the Digits of the MultidigitCounter */
	 int max_count = 0;  	/**< an integer variable max_count to hold the max Count value of the MultidigitCounter */
	cout << "Lab1_2_ModuloNCounter started." << endl << endl;
	cout << "Please enter the parameters of your Counter:"<<endl;
	cout<< "number of digits:";
	cin >> no_Of_Digits; /** Input digits*/
	cout<< "type:";
	cin >> max_count; /** Input type which is the max Count value*/

	/**Creating instance of CMultiDigitCounter
	 * @param no_Of_Digits
	 * @param max_count */
	CMultiDigitCounter *multiDigitCounter = new CMultiDigitCounter(no_Of_Digits,max_count);
	multiDigitCounter->display_MultiDigit_Counter(COUNTER_NAME); /** Display by Counter Name and no. of Digits*/
	multiDigitCounter->init_MultiDigit_Counter(); /** Calling setup method of MultidigitCounter*/
	for ( int i = 0; i < 400; i++)   /**Loop to print the Counter values */
	{
	 multiDigitCounter->calc_MultiDigit_Counter(); /** Calling calculate method of MultidigitCounter*/
	 multiDigitCounter->display_MultiDigit_Counter(COUNTER_VALUE);  /** Calling display method of MultidigitCounter*/
		if( i% max_count  == max_count-1) /** Formatting output based on max Count */
		{
			cout<<"\n";
		}
	}

	/** TO DO operator overloading */
	/** Prefix Operator Overloading Usage */
	++multiDigitCounter;
	cout<< "\n Prefix Operator Overloading "<< multiDigitCounter << endl;

	/** Postfix Operator Overloading Usage */
	multiDigitCounter++;
	cout<< "\n Postfix Operator Overloading "<< multiDigitCounter << endl;




	return 0;
}

