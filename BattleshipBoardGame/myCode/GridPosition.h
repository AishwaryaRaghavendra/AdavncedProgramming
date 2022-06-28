/*
 * GridPosition.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Aishwarya
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
#include <sstream>

/**
 *@brief Class GridPosition defined to get row and column from user check if its valid.
 * Also overloads cast to String, == and < operators.
 */
class GridPosition
{
private:

	/**< Member row of type char to hold Row */
	char row;

	/**< Member column of type int to hold Column */
	int column;

public:
	/**
	 * Parameterized Constructor defined to initialize  row and column.
	 * @param row holds the row of type char
	 * @param column holds the column of type int
	 */
	GridPosition(char row = 0, int column = 0);

	/**
	 * Parameterized Constructor defined to convert the string input 'position' as row and column.
	 *@param position holds the GridPosition of type string
	 */
	GridPosition(std:: string position);

	/**
	 * Method isValid() checks if 'A' ≤ row ≤ 'Z' and column > 0
	 *@return true if its valid else return false
	 */
	bool isValid() const;

	/**
	 * Method getRow() defined to get the row
	 *@return row of type char
	 */
	char getRow() const;

	/**
	 * Method getColumn() defined to get the column
	 *@return column of type int
	 */
	int getColumn() const;

	/**
	 * Method overloaded cast to String defined to concatenate row and column
	 *@return concatenated row and column as String
	 */
	operator std::string() const;

	/**
	 * Method overloaded== defined to check if the current grid position is the same as the other grid position entered
	 *@return true if check is valid else false
	 */
	bool operator==(GridPosition other) const;

	/**
	 * Method overloaded< defined to check if the current grid position is lesser than the next grid position
	 * so that the grid positions are ordered from top to bottom and left to right
	 *@return true if check is valid else false
	 */
	bool operator<(GridPosition other) const;

};

#endif /* GRIDPOSITION_H_ */
