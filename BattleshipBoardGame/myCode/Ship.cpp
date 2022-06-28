/*
 * Ship.cpp
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */
#include <cstdlib>
#include <iostream>
#include <set>
#include "GridPosition.h"
#include "Ship.h"

Ship::Ship(const GridPosition &bow, const GridPosition &stern): bow(bow), stern(stern)
{
}

bool Ship::isValid() const
{
	// Check for Horizontal or Vertical Direction
	if((bow.getRow() == stern.getRow()) || (bow.getColumn() == stern.getColumn()))
	{
		// Check for length of the ships are in between 2 and 5
		if ( length() >=2 && length() <= 5)
		{
			return true;
		}

	}
	return false;
}

GridPosition Ship::getBow() const
{
	return this->bow ;
}

GridPosition Ship::getStern() const
{
	return this->stern;
}

int Ship::length() const
{
	if(bow.getRow() == stern.getRow()) // Horizontal direction
	{
		return (abs(stern.getColumn() - bow.getColumn()) + 1 ); // Take absolute value of difference to consider bow column greater than stern column case
	}
	else
		if(bow.getColumn() == stern.getColumn()) // Vertical direction
		{
			return (abs(stern.getRow() - bow.getRow()) + 1); // Take absolute value of difference to consider bow row greater than stern row case
		}

	return 0;
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	int shipLen = this->length();
	std::set<GridPosition> occupiedArea;

	if(bow.getRow() == stern.getRow()) // Horizontal direction
	{
		if(bow.getColumn() < stern.getColumn())
		{
			for(int i = 0; i < shipLen; i++)
			{
				occupiedArea.insert(GridPosition(bow.getRow(), bow.getColumn() +i )); //insert the GridPosition
			}
			return occupiedArea;
		}
	}
	else if(bow.getColumn() == stern.getColumn()) // Vertical direction
	{
		if(bow.getRow() < stern.getRow())
		{
			for(int i = 0; i < shipLen; i++)
			{
				occupiedArea.insert(GridPosition(bow.getRow() +i , bow.getColumn()));
			}
			return occupiedArea;
		}
	}
	return occupiedArea;

}



const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedArea;
	for(auto pos: this->occupiedArea())   /** Steps: Iterate through occupied area of the ship */
	{
		/** {(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)} 8 neighbouring positions for a gridposition in occupied Area */
		for(int row = -1; row <= 1; row++)
		{
			for(int col = -1; col <=1 ; col++)
			{
				//Traverse through neighbours and save
				char blockedAreaRow = pos.getRow() + row;
				int blockedAreaCol = pos.getColumn( ) + col;
				if(GridPosition (blockedAreaRow,blockedAreaCol).isValid()) /** check if GridPosition is valid (row is A-Z and col>0)    */
				{
					blockedArea.insert(GridPosition(blockedAreaRow,blockedAreaCol)); /** insert GridPosition  */
				}
			}
		}
	}
	return blockedArea;

}
