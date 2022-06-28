/*
 * ConsoleView.cpp
 *
 *  Created on: Dec 20, 2020
 *      Author: Aishwarya
 */
#include<iostream>
#include "ConsoleView.h"


ConsoleView::ConsoleView(Board* board): board(board)
{
	/** dynamic memory allocation for 2D char array of player's grid */
	playerGrid= new char*[this->board->getRows()];
	for(int row = 0; row < board->getRows(); row++)
	{
		playerGrid[row] = new char [this->board->getColumns()];
	}

	/** dynamic memory allocation for 2D char array of opponent's grid */
	enemyGrid = new char*[this->board->getRows()];
	for(int row = 0; row < this->board->getRows(); row++)
	{
		enemyGrid[row] = new char [this->board->getColumns()];
	}

	/**Initialise board with '~' char */
	for(int row=0; row < this->board->getRows(); row++)
	{
		for(int col= 0; col< this->board->getColumns(); col++)
		{
			playerGrid[row][col] = '~';
			enemyGrid[row][col] = '~';
		}
	}

}

ConsoleView::~ConsoleView()
{
	for(int row=0; row < board->getRows(); row++) {
		delete [] playerGrid[row];
	}
	delete [] playerGrid; 		/**delete the allocated memory for playerGrid */


	for(int row=0; row < board->getRows(); row++) {
		delete [] enemyGrid[row];
	}

	delete[] enemyGrid; 		/**delete the allocated memory for enemyGrid */
}

void ConsoleView::placeShipCode()
{
	for(auto numOfShips: board->getOwnGrid().getShips()) 	 /** Iterate over all ships in ownGrid */
	{
		for(auto shipOccupied: numOfShips.occupiedArea()) 		/** Iterate over occupiedArea which is a set of grid positions for each ship */
		{
			char rowChar = shipOccupied.getRow();
			int column = shipOccupied.getColumn();
			int row = static_cast<int>(rowChar)- 65;
			int col = column -1;
			playerGrid[row][col] = '#';			/** Place '#' in playerGrid for the ships's occupied area*/
		}
	}

	for(auto shot: board->getOwnGrid().getShotAt())
	{
		char rowChar = shot.getRow();
		int column = shot.getColumn();
		int row = static_cast<int>(rowChar)- 65;
		int col = column -1;
		if(row >= 0 && row < board->getRows() && col >=0 && col < board->getColumns() )
		{
			playerGrid[row][col] = board->getOwnGrid().takeBlow(shot);	/**Return impact of the shot in playerGrid after takeBlow*/
		}
	}
}

void ConsoleView::print()
{
	std::cout<<" ";

	for(int grids=0; grids<2; ++grids) 			/** to iterate over playerGrid and enemyGrid */
	{
		/** Column header print */
		for(int col = 0; col < board->getColumns(); col++)
		{
			if(((col+1)/10)>0)
			{
				std::cout<<" "<<(col+1)/10;
			}
			else
			{
				std::cout<< "  ";
			}
		}
		std::cout<<"     ";
	}
	std::cout<<std::endl << " ";

	for(int grids=0; grids<2; ++grids)
	{
		for(int col = 0; col < board->getColumns(); col++)
		{
			std::cout<<" "<<(col + 1)%10;
		}
		std::cout<<"     ";
	}
	std::cout<<std::endl;

	for(int row = 0 ; row <board->getRows(); row++)
	{
		std::cout << static_cast<char>(row + 65) << " "; 	/** Row header print in Alphabets for playerGrid */

		for(int col = 0 ; col< board->getColumns(); col++)
		{
			placeShipCode(); 							 /** Calling placeShipCode() to place '#' in playerGrid for the ships's occupied area */
			std::cout<<playerGrid[row][col]<<" "; 	 	/** Print playerGrid */
		}

		std::cout<< "   " << static_cast<char>(row + 65) << " ";	/** Row header print in Alphabets for enemyGrid */

		for(int col = 0 ; col< board->getColumns() ; col++)
		{
			std::cout<<enemyGrid[row][col]<<" "; 	 /** Print enemyGrid */
		}

		std::cout <<std::endl;
	}
	std::cout <<std::endl;
}




