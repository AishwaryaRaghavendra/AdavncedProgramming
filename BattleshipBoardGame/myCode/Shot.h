/*
 * Shot.h
 *
 *  Created on: Jan 3, 2021
 *      Author: Aishwarya
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @brief Class Shot defined to get the targetPosition on the grid.
 * Also Enumerator is defined for HIT,NONE,SUNKEN.
 */
class Shot
{
	/**< targetPosition Object of GridPosition class also
	 *  a member of Shot Class  */
	GridPosition targetPosition;
public:

	/**
	 * @brief Parameterized Constructor defined initializes the shot on target using GridPosition object.
	 *
	 * @param targetPosition of type GridPosition to set a target
	 */
	Shot(GridPosition targetPosition);

	/**
	 * @brief getTargetPosition() Member function defined returns the target position as GridPosition.
	 */
	const GridPosition getTargetPosition() const;

	/**
	 * @brief Enumeration created to return Impact on the ship when blow taken.
	 */
 typedef enum
	{
		NONE = '^',
		HIT = 'O',
		SUNKEN = 'X'
	}Impact;


};


#endif /* SHOT_H_ */
