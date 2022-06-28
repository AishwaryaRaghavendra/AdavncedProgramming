/*
 * GridPosition.cpp
 *
 *  Created on: Dec 19, 2020
 *      Author: Aishwarya
 */

#include "GridPosition.h"

GridPosition::GridPosition(char row, int column): row(row), column(column)
{
}

GridPosition::GridPosition(std::string position)
{
	this->row = position[0];
	std::stringstream digit;
	digit << position.substr(1,position.length());
	digit >> this->column;
}


bool GridPosition::isValid() const
{
	if(((row >= 'a' && row <= 'z') || (row >= 'A' && row <= 'Z')) && (column > 0))
	{
		return true;
	}

	return false;
}

char GridPosition::getRow() const
{
	return this->row;
}

int GridPosition::getColumn() const
{
	return this->column;

}

GridPosition::operator std::string() const
{

	return (this->row + std::to_string(this->column));
}

bool GridPosition::operator == (GridPosition other) const
{
	if((this->row == other.row) && (this->column == other.column))
	{
		return true;
	}

	return false;
}

bool GridPosition::operator< (GridPosition other) const
{
	if(this->row == other.row) // If Horizontal
	{
		if(this->column < other.column)
		{
			return true;
		}
	}
	else
		if(this->column == other.column) // If Vertical
		{
			if(this->row < other.row)
			{
				return true;
			}
		}

	return false;

}


