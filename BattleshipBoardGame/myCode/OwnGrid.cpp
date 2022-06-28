/*
 * OwnGrid.cpp
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#include "OwnGrid.h"
#include <iostream>
#include <string>

OwnGrid::OwnGrid(int rows = 0, int columns = 0): rows(rows), columns(columns)
{
	shipMap.insert (std::pair<int, int>(5, 1));		/** ship type: Carrier, Length: 5, Number of ships: 1  		*/
	shipMap.insert (std::pair<int, int>(4, 2));		/** ship type: Battleship, Length: 4, Number of ships: 2  	*/
	shipMap.insert (std::pair<int, int>(3, 3));		/** ship type: Destroyer, Length: 3, Number of ships: 3  	*/
	shipMap.insert (std::pair<int, int>(2, 4));		/** ship type: Submarine, Length: 2, Number of ships: 4 	*/
}

int OwnGrid::getRows() const
{
	return this->rows;
}

int OwnGrid::getColumns() const
{
	return this->columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	/** Steps: check for ship placement within and at the edge of the grid and beyond the edge of the grid, ship is not placed. */
	if (ship.getBow().getRow() <= static_cast<char>(rows + 64) && ship.getStern().getRow() <= static_cast<char>(rows + 64)
			&& ship.getBow().getColumn() <= columns && ship.getStern().getColumn() <= columns)
	{
		if (ship.isValid()) /** check for valid placement of the ship i.e either in horizontal or vertical direction and length between 2 and 5 */
		{
			if (ships.empty()) /** check initially the ship vector before adding any ships is empty */
			{
				if (shipMap[ship.length()] > 0) /** check if the number of ships value associated with the length is greater zero */
				{
					ships.push_back(ship); /** Push the desired ship into ships vector */
					--shipMap[ship.length()]; /** decrement the number of ships value associated with the given length */
					return true; /** First Ship is placed */
				}
			}
			else
			{
				/** To place next subsequent ships */
				if (shipMap[ship.length()] > 0) /** check if the number of ships value associated with the length is greater zero */
				{
					ships.push_back(ship); /** Push the desired ship into ships vector */
					--shipMap[ship.length()]; /** decrement the number of ships value associated with the given length  */
					return true; /** Next Ship is placed */
				}

				std::set<GridPosition> newOccupiedArea = ship.occupiedArea(); /** Copy of occupied area of the desired new ship to be placed */
				std::set<GridPosition> intersectArea;
				for (auto itr : ships) /** Iterate over ships already placed on the OwnGrid */
				{
					std::set<GridPosition> copyBlockedArea = itr.blockedArea(); /** Copy of already placed ship's blocked area */
					/**Check for Ship must not touch each other by taking the set intersection of already placed ship's blocked area and new ship's occupied area and evaluating it to be an empty set */
					std::set_intersection(newOccupiedArea.begin(), newOccupiedArea.end(), copyBlockedArea.begin(), copyBlockedArea.end(), std::inserter(intersectArea, intersectArea.begin()));
					if (intersectArea.empty())
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return this->ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	shotAt.insert(shot.getTargetPosition()); /** Steps: First insert the shot of desired targetPosition into shotAt set */

	for (auto ship : ships) /** Iterate over all ship's to find the hit, miss or sunk */
	{
		std::set<GridPosition> copyOccupiedArea = ship.occupiedArea();

		for (auto occupied : copyOccupiedArea) /** Iterate over the ship's occupiedArea which is set of gridPosition */
		{
			if (occupied == shot.getTargetPosition()) /** To check if Impact of the shot after takeBlow is a Hit by comparing targetPosition and ship's occupied gridPosition */
			{
				std::set<GridPosition> intersect;
				std::set_intersection(copyOccupiedArea.begin(), copyOccupiedArea.end(), shotAt.begin(), shotAt.end(), std::inserter(intersect, intersect.begin()));

				/** If the size of the intersection is one less than the length of the ship, the current hit is the final one and ship is sunk */
				if(int(intersect.size()) == ship.length())
				{
					return Shot::Impact::SUNKEN; /** Return shot Impact is SUNKEN */
				}
				return Shot::Impact::HIT; /** Return shot Impact is HIT */
			}
		}
	}
	return Shot::Impact::NONE; /** Else return shot Impact is NONE */
}

const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return this->shotAt;
}
