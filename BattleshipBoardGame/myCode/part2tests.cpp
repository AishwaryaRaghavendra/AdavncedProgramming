/*
 * part2tests.cpp
 *
 *  Created on: Dec 28, 2020
 *      Author: Aishwarya
 */

#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "ConsoleView.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */

void assertTrueTest2(bool condition, std::string failedMessage) {
	if (!condition) {
		std::cout << failedMessage << std::endl;
	}
}


/**
 * Tests for task 2.2.1 and task 2.2.2 : for Display and Arrangement Rules
 */
void part2tests()
{
	int row = 0;
	int col = 0;
	std::cout << std::endl;
	std::cout << "Enter no. of Rows and no. of Columns for the Board" << std::endl;
	std::cin>> row >> col;

	Board board(row,col);

	/** Check for Blocked area */

	assertTrueTest2(Ship{GridPosition{"H5"},GridPosition{"H8"}}.blockedArea()
			== std::set<GridPosition>{GridPosition{"G4"},GridPosition{"G5"},GridPosition{"G6"},GridPosition{"G7"},GridPosition{"G8"},GridPosition{"G9"},
		GridPosition{"H4"},GridPosition{"H5"},GridPosition{"H6"},GridPosition{"H7"},GridPosition{"H8"},GridPosition{"H9"},
		GridPosition{"I4"},GridPosition{"I5"},GridPosition{"I6"},GridPosition{"I7"},GridPosition{"I8"},GridPosition{"I9"}},
		"Blocked area is not correct");

	assertTrueTest2(Ship{GridPosition{"D10"},GridPosition{"E10"}}.blockedArea()
			== std::set<GridPosition>{GridPosition{"C9"},GridPosition{"C10"},GridPosition{"C11"},
		GridPosition{"D9"},GridPosition{"D10"},GridPosition{"D11"},
		GridPosition{"E9"},GridPosition{"E10"},GridPosition{"E11"},
		GridPosition{"F9"},GridPosition{"F10"},GridPosition{"F11"}},
		"Blocked area is not correct");

	/** Ships must be placed only Horizontally or Vertically, form a straight line */

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B4"}}), " Ship B2 to B4 is not placed"); //Place first ship - 1st Destroyer

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"D4"},GridPosition{"G4"}}), "Ship  D4 to G4 not is not placed"); //Place second ship - 1st Battleship

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"F6"},GridPosition{"F9"}}), "Ship F6 to F9 is not placed"); //Place third ship - 2nd Battleship

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"G10"},GridPosition{"I8"}}), "Ship G10 to I8 is not placed as its diagonal"); //Ships not placed diagonally

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"E3"},GridPosition{"C1"}}), "Ship E3 to C1 is not placed as its diagonal"); //Ships not placed diagonally



	/** Ships may be placed at the edge of the grid */

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"I1"},GridPosition{"J1"}}), "Ship I1 to J1 is not placed");  // Place fourth ship - 1st Submarine

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"J6"},GridPosition{"J10"}}), "Ship J6 to J10 is not placed");  // Place fifth ship - 1st Carrier

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"A10"},GridPosition{"B10"}}), "Ship A10 to B10 is not placed");  // Place Sixth ship - 2nd Submarine


	/** Length of the ship is in between 2 and 5 */

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"I8"},GridPosition{"I8"}}), "Ship I8 to I8 is not placed. Min ship length is 2"); //  Ship is not  placed since Length is 0.

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"D10"},GridPosition{"I10"}}),"Ship D10 to I10 is not placed. Max ship length is 5"); //  Ship is not  placed since max allowed length is 5.



	/** More than 10 ships cannot be placed for one Player */

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"A6"},GridPosition{"A8"}}), "Ship A6 to A8 is not placed"); // Seventh ship is placed - 2nd Destroyer

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"C5"},GridPosition{"C7"}}), "Ship C5 to C7 is not placed"); // Eigth Ship is placed. 3rd Destroyer

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"H5"},GridPosition{"H6"}}), "Ship H5 to H6 is not placed"); // Ninth Ship is placed - 3rd Submarine

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"H8"},GridPosition{"H9"}}), "Ship H8 to H9 is not placed"); // Tenth Ship is placed - 4th Submarine

	assertTrueTest2(board.getOwnGrid().placeShip(Ship{GridPosition{"J3"},GridPosition{"J4"}}), "Ship J3 to J4 is not placed. More than 10 ships not placed!"); //Ships more than 10 not placed



	/** Print the board */

	ConsoleView(&board).print();


}

