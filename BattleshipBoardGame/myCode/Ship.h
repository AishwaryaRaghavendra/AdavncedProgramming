/*
 * Ship.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include <set>

/**
 *@brief Class Ship defined for ship and has two grid positions namely bow and stern.
 * Checks if the grid positions for bow and stern are valid.
 * Returns bow, stern and length of the Ship.
 * Calculates the occupied area and blocked area for the ship and returns the occupied area and blocked area as set of grid positions.
 */
class Ship
{
private:
	/**< Member bow of type GridPosition class */
	GridPosition bow;

	/**< Member stern of type GridPosition class */
	GridPosition stern;

public:
	/**
	 * Parameterized Constructor is defined initialize the bow and stern that are passed as its arguments.
	 *@param bow holds the ship's bow of type GridPosition
	 *@param stern holds the ship's stern of type GridPosition
	 */
	Ship(const GridPosition& bow, const GridPosition& stern );

	/**
	 * checks if the ship is positioned either horizontally or vertically and whether the ship's length is between 2 and 5.
	 * @return true if check is valid else false
	 */
	bool isValid() const;

	/**
	 * Method getBow() defined to get the bow.
	 *@return bow value of GridPosition
	 */
	GridPosition getBow() const;

	/**
	 * Method getStern() defined to get the stern.
	 *@return stern value of GridPosition
	 */
	GridPosition getStern() const;

	/**
	 * Method length() defined to calculate the length of the ship based on the distance between  bow and stern.
	 *@return ship length of type int
	 */
	int length() const;

	/**
	 * Method occupiedArea() returns the set<> of grid positions that are occupied by the ship.
	 *@return occupied Area of the ship as set<> of GridPosition.
	 */
	const std::set <GridPosition> occupiedArea() const;

	/**
	 * Method blockedArea() returns the set<> of grid positions that are occupied by the ship and also all the 8 surrounding grid positions.
	 *@return blockedArea Area of the ship as set<> of GridPosition.
	 */
	const std::set <GridPosition> blockedArea() const;


};

#endif /* SHIP_H_ */
