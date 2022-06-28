/*
 * Shot.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: Aishwarya
 */

#include "Shot.h"


Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition)
{
}

const GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}
