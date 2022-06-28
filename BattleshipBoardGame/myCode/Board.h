
/*
 * Board.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OpponentGrid.h"
#include "OwnGrid.h"

/**
 * @brief Class Board defined to provide access to the OwnGrid and OpponentGrid using the getter-functions
 */
class Board
{
private:
	/**< Member ownGrid defined as object of OwnGrid class  */
	OwnGrid ownGrid;

	/**<Member opponentGrid defined as object of OpponentGrid class */
	OpponentGrid opponentGrid;

public:
	/**
	 * Parameterized Constructor defined sets the rows and columns for OwnGrid and OpponentGrid.
	 * @param rows holds the no. of rows of type int
	 * @param columns holds the no. of columns of type int
	 */
	Board(int rows, int columns);

	/**
	 * Method getRows() to get the rows of OwnGrid.
	 * @return rows of type int
	 */
	int getRows() const;

	/**
	 * Method getColumns() to get the columns of OwnGrid.
	 * @return columns of type int
	 */
	int getColumns() const;

	/**
	 * Method getOwnGrid() to get the ownGrid
	 * @return ownGrid of type OwnGrid class
	 */
	OwnGrid& getOwnGrid();

	/**
	 * Method getOpponentGrid() to get the opponentGrid
	 * @return opponentGrid of type OpponentGrid class
	 */
	OpponentGrid& getOpponentGrid();

};

#endif /* BOARD_H_ */
