/*
 * OpponentGrid.cpp
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */

#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(int rows, int columns): rows(rows), columns(columns)
{
}


int OpponentGrid::getRows() const
{
	return this->rows;
}

int OpponentGrid::getColumns() const
{
	return this->columns;
}


void OpponentGrid::shotResult(const Shot &shot, Shot::Impact shotImpact)
{
shots.insert(std::pair<GridPosition, Shot::Impact>(shot.getTargetPosition(),shotImpact));
//TODO
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return this->shots;
}
