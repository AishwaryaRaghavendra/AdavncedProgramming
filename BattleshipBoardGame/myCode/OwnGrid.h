/*
 * OwnGrid.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include "Ship.h"
#include "Shot.h"


/**
 *@brief Class OwnGrid has its grid of rows and columns.
 * Holds the vector of ships.
 * Holds the map of ship's length and no. of ships.
 * Places the ship in its grid.
 * Takes the blow and returns the Impact for that blow.
 */
class OwnGrid
{
private:
	/**< Member to hold its rows of type int */
	int rows;

	/**< Member to hold its columns of type int */
	int columns;

	/**< Member ships to hold the vector of ships of type Ship class */
	std::vector<Ship> ships;

	/**< Member shipMap to hold map<> of ship length and no. of ships */
	std::map<int,int> shipMap;

	/**< Member shotAt to hold set<> of targets of type GridPosition  */
	std::set<GridPosition> shotAt;

public:

	/**
	 * Parameterized Constructor defined initializes its rows, columns and a map pair of the ship length and no. of ships.
	 * @param rows holds the no. of rows of type int.
	 * @param columns holds the no. of columns of type int.
	 */
	OwnGrid(int rows, int columns);

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
	 * Method placeShip defined to place the ship in OwnGrid by checking all the Arrangement Rules.
	 * @param ship object of Ship class passed as reference argument. Sets the bow and stern grid positions for placing the ship.
	 * @return true if all arrangement checks for placing ships are valid else false.
	 */
	bool placeShip(const Ship& ship);

	/**
	 * Method getShips() to return the vector of ships.
	 * @return vector of ships of type Ship class
	 */
	const std::vector<Ship> getShips() const;

	/**
	 * Method takeBlow() defined takes the shot at targetPosition.
	 * checks if the targetPosition is in the occupied area of the ship.
	 * checks if there is a Impact of HIT, NONE or SUNK on the ship of the OwnGrid and returns that Impact.
	 * @param shot object of Shot class passed as reference argument. Sets the shot at targetPosition.
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * Method getShotAt() to return the set<> targetPositions.
	 * @return shotAt of type set<>
	 */
	const std::set<GridPosition> getShotAt() const;

};

#endif /* OWNGRID_H_ */
