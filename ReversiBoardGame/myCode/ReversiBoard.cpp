/*
 * ReversiBoard.cpp
 *
 *  Created on: Nov 23, 2020
 *      Author: Aishwarya
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "ReversiBoard.h"

ReversiBoard::ReversiBoard()
{
	m_Board[ROWS][COLS] = { 0 };
	m_Col = 0;
	m_Row = 0;
	m_CompScore = 0;
	m_HumanScore = 0;

}

ReversiBoard::ReversiBoard(char board[ROWS][COLS])
{
	m_Board[ROWS][COLS] = board[ROWS][COLS];

}

ReversiBoard::~ReversiBoard()
{
	// TODO Auto-generated destructor stub
}


/** method to set the board array blank and 4 center tiles to Player and opponent tiles
 *@param board[ROWS][COLS] is the Board array of type 2Dchar
 */
void ReversiBoard::init_Board(char board[ROWS][COLS])
{
	for (int row = 0;row < ROWS;row++)
	{
		for (int col =0; col < COLS; col++)
		{
			m_Board[row][col] = ' ';
		}
	}
	/* Placing the initial four tiles of the Player and Computer in the center of the Board*/
	m_Board[3][3] = 'W';
	m_Board[3][4] = 'B';
	m_Board[4][3] = 'B';
	m_Board[4][4] = 'W';

}

/** method to draw the board array 8*8 with desired format
 *@param board[ROWS][COLS] is the Board array of type 2Dchar
 */
void ReversiBoard::draw_Board()
{
	cout << "     0   1   2   3   4   5   6   7" << endl;
	cout << "   +---+---+---+---+---+---+---+---+" << endl;
	for (int row = 0;row < ROWS;row++)
	{
		cout <<row;
		cout << "  | " ;
		for (int col =0; col < COLS; col++)
		{
			cout << m_Board[row][col] << " | ";
		}
		cout << endl;
		cout << "   +---+---+---+---+---+---+---+---+" << endl;
	}

}


/** execute_Move(): Makes a move. This places the tile on a disk
 *  Flips all the opponent's tiles for that move.
 * @param board[ROWS][COLS] of type 2D char is the board array
 * @param row index of type int
 * @param col index of type int
 * @param playerTile of type char identifies the either Human or Computer player
 * @return flipCount of type int denotes the number of discs flipped*/
int ReversiBoard::execute_Move(char board[ROWS][COLS],  int row,  int col, char playerTile)
{
	int flipCount = 0;
	int row_Direction = 0; /* Row increment              */
	int col_Direction = 0; /* Column increment           */
	int r = 0; /* Row index for searching    */
	int c = 0; /* Column index for searching */
	char opponentTile = 0;

	/* Identify player and opponent */
	if (playerTile == HUMAN)
	{
		opponentTile = COMPUTER;
	}
	else
	{
		opponentTile = HUMAN;
	}
	m_Board[m_Row][m_Col] = playerTile; /* Inserting the player tile   */

	/* Check all the squares around this square */
	/* for the opponent's tile                */
	/*Looping iteration goes through these combinations of row and col around a disk {(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)} */
	for (row_Direction = -1; row_Direction <= 1; row_Direction++)
	{
		for (col_Direction = -1; col_Direction <= 1; col_Direction++)
		{
			/** Check for out of Bound Array and Current disk */
			if (row + row_Direction < 0 || row + row_Direction >= ROWS || col + col_Direction < 0
					|| col + col_Direction >= COLS || (row_Direction == 0 && col_Direction == 0))
				continue;
			/* Now check the disk */
			if(m_Board[row + row_Direction][col + col_Direction] == opponentTile)
			{

				/** If we find the opponent, move in the reference direction along the opponent's tiles
				 searching for a player's tile and record the row and col along that direction */
				r = row + row_Direction; /** Move to          */
				c = col + col_Direction; /** opponent disk  */

				/** Look for a player's tile in the reference direction */
				while(1)
				{
					r += row_Direction; /* Go to next disk in the reference direction */
					c += col_Direction;

					/** If we encounter a blank disk, then stop */
					if (m_Board[r][c] == ' ')
						break;

					/** If we move outside the array, then stop */
					if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
						break;

					/**  If the disk has a player's tile then it is a legal move          */
					if (m_Board[r][c] == playerTile)
					{
						/**To flip the tiles, move in the reverse direction until we reach the original disk, noting all the tiles along the way.*/
						while (m_Board[r -= row_Direction][c -= col_Direction] == opponentTile)
							m_Board[r][c] = playerTile; /* Flipping tiles */
						flipCount++;
						break;
					}
				}
			}
		}
	}

	/** Reset board if nothing was flipped... illegal move */
	if (flipCount == 0)	{
		m_Board[m_Row][m_Col] = ' ';
	}

	return flipCount;
}


/**isMovePossible() Checks to see if the players can make a valid move on the game
 * @return 1 if a move was possible, 0 otherwise.
 * @param board[ROWS][COLS] of type 2D char is the board array
 * @param player of type char identifies the either Human or Computer player */
int ReversiBoard::isMovePossible(const char board[ROWS][COLS], char playerTile)
{

	int row_Direction = 0; /* Row increment around a disk    */
	int col_Direction = 0; /* Column increment around a disk */
	int r = 0; /* Row index while searching         */
	int c = 0; /* Column index while searching      */
	char opponentTile = 0; /* Identify player and opponent */

	if (playerTile == HUMAN)
	{
		opponentTile = COMPUTER;
	}
	else
	{
		opponentTile = HUMAN;
	}

	/** Find disks for Correct Moves. */
	/** A correct move must be on a blank disk and must enclose at least one opponent disk in between two player disks */
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (m_Board[row][col] != ' ') /** Checking if its not a blank disk?  */
				continue; /** No - so on to the next iteration */

			/** Check all the disks around the blank disk  */
			/** for the opponents token  */
			/*Looping iteration goes through these combinations of row_Direction and col_Direction
			 *  {(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)} */
			for (row_Direction = -1; row_Direction <= 1; row_Direction++)
			{
				for (col_Direction = -1; col_Direction <= 1; col_Direction++)
				{
					/** Check for out of Bound Array and Current disk */
					if (row + row_Direction < 0 || row + row_Direction >= ROWS || col + col_Direction < 0 || col + col_Direction >= COLS
							|| (row_Direction == 0 && col_Direction == 0))
						continue;

					/** Now check the disk */
					if (m_Board[row + row_Direction][col + row_Direction] == opponentTile)
					{
						/** If we find the opponent, move in the reference direction  */
						/** along the opponent tokens searching for a player's token */
						r = row + row_Direction; /** Move to          */
						c = col + row_Direction; /** opponent disk  */

						/** Look for a player's disk in the reference direction */
						while(1)
						{
							r = row + row_Direction; /* Go to next disk in the reference direction */
							c = col + col_Direction;

							/** If we move outside the array, then stop */
							if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
								break;

							/** If we encounter a blank disk, then stop */
							if (m_Board[row][col] == ' ')
								break;

							/**  If the disk has a player's token */
							/**  then it is a correct move          */
							if (m_Board[r][c] == playerTile)
								break;
						}
					}
				}
			}
		}
	}

	return 1;
}


/** Calculates the score for the current board position for the player.
 * Player tiles score +1, Opponent tiles score -1
 *@param board[ROWS][COLS] is the input board of type 2D char array.
 *@param player of type char identifies the input player
 *@param humanScoreOut is value of the score output for the Human of type int
 *@param compScoreOut is value of the score output for the Computer of type int
 */
void ReversiBoard::set_CurrPos_Scores(char board[ROWS][COLS], int &humanScoreOut, int &compScoreOut)
{
	/* Check all board squares */
	for(int row = 0; row < ROWS; row++)
		for(int col = 0; col < COLS; col++)
		{
			if(m_Board[row][col] == HUMAN) /** Increment the score for the Human tiles */
			{
				humanScoreOut +=1;
			}
			if(m_Board[row][col] == COMPUTER) /** Increment the score for the Computer tiles */
			{
				compScoreOut +=1;
			}
		}

}

/** method computer_Move() is the best Move for which the opponent's best possible move score is a minimum.
 *@param board[ROWS][COLS] is the board of type 2D char array.                             *
 *@param moves[ROWS][COLS] is the moves array that denotes the valid moves.    *
 *@param computer identifies the computer
 *@return flipcount for the Computer Moves against the Human*/
int ReversiBoard::makeComputer_Move(char board[][COLS], char playerTile)
{

	int best_Row = 0;      /* Best row index          */
	int best_Col = 0;         /* Best column index       */
	int humanScore = 0;		/** Score for Human tiles */
	int compScore = 0;		/** Score for Computer tiles */
	int flipCount = 0;		/* disk Flip count for player move */
	int bestScore = -1;  	/** the first move the code checks will be set to the first bestMove */

	char dupe_board[ROWS][COLS] = {0}; /* duplicate copy of board     */

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			/** make copy of the board array */
			dupe_board[row][col] = m_Board[row][col];

			if(isMovePossible(dupe_board,playerTile) == 0)             /** is Valid Move Possible?      */
				continue;                      					/** if NO, Go to the next iteration        */

			/** Let computer make a move on the duplicate array using execute_Move() and returns valid flip disk count if any */
			execute_Move(dupe_board, row, col, playerTile);
			set_CurrPos_Scores(dupe_board, humanScore,compScore);
			if (compScore > bestScore)
			{
				bestScore = compScore;
				best_Row = row;  	/** Record best move row         */
				best_Col = col;		/** Record best move Column         */
			}
		}
	}

	flipCount = execute_Move(board, best_Row, best_Col, playerTile);
	return flipCount;
}



/** calc_Final_Scores() finds the final score for the Computer and Human after all moves were played */
void ReversiBoard::calc_Final_Scores()
{
	//	char opponent = (playerTile == HUMAN) ? COMPUTER: HUMAN;  /* Identify opponent's tile state */
	/** Find final scores */
	for(int row = 0; row < ROWS; row++)
	{
		for(int col = 0; col < COLS; col++)
		{
			if(m_Board[row][col] == HUMAN)
			{
				m_HumanScore +=1;
			}
			if(m_Board[row][col] == COMPUTER)
			{
				m_CompScore +=1;
			}
		}
	}
	cout << "The final score is: "<<endl;
	cout << "Computer  " << m_CompScore <<endl;
	cout << "user_score  " << m_HumanScore <<endl;
	if (m_CompScore > m_HumanScore )
	{
		cout << "Computer wins"  <<endl;
	}
	else if (m_CompScore < m_HumanScore )
	{
		cout << "You win"  <<endl;
	}
	else
	{
		cout << "Its a tie"  <<endl;
	}
}

