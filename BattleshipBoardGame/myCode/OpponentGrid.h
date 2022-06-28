/*
 * OpponentGrid.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include <map>
#include <vector>
#include "Ship.h"
#include "Shot.h"


/**
 * @brief Class OpponentGrid defined has its grid of rows and columns.
 * Holds a map of GridPosition and Impact of the Shot.
 * Method to set shots and calculate shot results based on the Impact.
 * Holds vector of sunkenShips
 */
class OpponentGrid
{
private:
	/**< Member to hold its rows of type int */
	int rows;

	/**< Member to hold its columns of type int */
	int columns;

	/**< Member sunkenShips to hold the vector of sunken ships of type Ship class */
	std::vector<Ship> sunkenShips;

	/**< Member shots to hold map<> of key:GridPosition and value:Impact of the shot.  */
	std::map<GridPosition,Shot::Impact> shots;

public:
	/**
	 * Parameterized Constructor defined initializes its rows and columns.
	 * @param rows holds the no. of rows of type int.
	 * @param columns holds the no. of columns of type int.
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * Method getRows() defined to get the rows.
	 *@return rows of type int
	 */
	int getRows() const;

	/**
	 * Method getColumns() defined to get the columns.
	 *@return columns of type int.
	 */
	int getColumns() const;

	/**
	 * Method shotResult() defined to set the shot and calculate the shot results and updates the vector of sunken ships.
	 * @param shot object of Shot class passed as reference argument
	 * @param Impact of Shot class
	 */
	void shotResult(const Shot& shot, Shot:: Impact);

	/**
	 * Method getShotsAt() to return map<> of GridPosition and Impact of the shot.
	 *@return shots which is a map<> of key:GridPosition and value:Impact of the shot .
	 */
	const std::map<GridPosition, Shot::Impact>& getShotsAt() const;
};

#endif /* OPPONENTGRID_H_ */
