/*
 * ConsoleView.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

/**
 * @brief class ConsoleView shows the current state of the board on the Console.
 * It obtains the information about the state of the game from Board and writes it to the console using print method
 */
class ConsoleView
{
private:

	/**< Member board pointer to an instance of Board class. */
	Board* board;

	/**<  Member playerGrid defined for pointer to pointer 2D char array Dynamic Memory Allocation */
	char **playerGrid;

	/**<  Member enemyGrid defined for pointer to pointer 2D char array Dynamic Memory Allocation */
	char **enemyGrid;

	/**< Method placeShipCode() defined for placing ship's occupied area with '#' in playerGrid created here*/
	void placeShipCode();

public:
	/**
	 * Parameterized Constructor defined to initialize the Board for player and enemy grids
	 *@param board to display the board of playerGrid and enemyGrid
	 */
	ConsoleView(Board* board);

	/**
	 * Destructor defined to delete the initialized memory for playerGrid and enemyGrid .
	 */
	virtual ~ConsoleView();

	/**
	 * Method print() defined to print the Board for player and enemy
	 */
	void print();

};

#endif /* CONSOLEVIEW_H_ */
