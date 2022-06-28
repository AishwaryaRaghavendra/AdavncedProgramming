/*
 * part3tests.cpp
 *
 *  Created on: Jan 9, 2021
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

void assertTrueTest3(bool condition, std::string failedMessage) {
	if (!condition) {
		std::cout << failedMessage << std::endl;
	}
}
/**
 * Tests for task 2.3 for Shots
 */

void part3tests()
{

	std::cout<<std::endl<<std::endl;
	Board board(10,10);

	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B4"}}), " Ship B2 to B4 is not placed"); //Place first ship - 1st Destroyer
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"D4"},GridPosition{"G4"}}), "Ship  D4 to G4 not is not placed"); //Place second ship - 1st Battleship
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"F6"},GridPosition{"F9"}}), "Ship F6 to F9 is not placed"); //Place third ship - 2nd Battleship
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"A6"},GridPosition{"A8"}}), "Ship A6 to A8 is not placed"); // Seventh ship is placed - 2nd Destroyer
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"C5"},GridPosition{"C7"}}), "Ship C5 to C7 is not placed"); // Eigth Ship is placed. 3rd Destroyer
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"H5"},GridPosition{"H6"}}), "Ship H5 to H6 is not placed"); // Ninth Ship is placed - 3rd Submarine
	assertTrueTest3(board.getOwnGrid().placeShip(Ship{GridPosition{"H8"},GridPosition{"H9"}}), "Ship H8 to H9 is not placed"); // Tenth Ship is placed - 4th Submarine

	/** @brief OwnGrid with Ships Taking Blows */

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"C5"}})== Shot::Impact::HIT), "A Blow at GridPosition C5 has No Return of HIT Impact");
	ConsoleView(&board).print();

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"D5"}})== Shot::Impact::NONE), "A Blow at GridPosition D5 has No Return of NONE Impact");
	ConsoleView(&board).print();

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"A6"}})== Shot::Impact::HIT), "A Blow at GridPosition A6 has No Return of HIT Impact");
	ConsoleView(&board).print();

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"A5"}})== Shot::Impact::NONE), "A Blow at GridPosition A5 has No Return of NONE Impact");
	ConsoleView(&board).print();

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"H5"}})== Shot::Impact::HIT), "A Blow at GridPosition H5 has No Return of HIT Impact");
	ConsoleView(&board).print();

	assertTrueTest3((board.getOwnGrid().takeBlow(Shot{GridPosition{"H6"}})== Shot::Impact::SUNKEN), "A Blow at GridPosition H6 has No Return of SUNKEN Impact");
	ConsoleView(&board).print();

}


