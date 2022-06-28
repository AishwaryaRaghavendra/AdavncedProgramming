/*
 * ReversiBoard.h
 *
 *  Created on: Nov 23, 2020
 *      Author: Aishwarya
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_


/* Row and Column Size of the Board - must be even */
const int ROWS = 8;
const int COLS = 8;

/** Tiles */
const char HUMAN = 'W';
const char COMPUTER = 'B';


class ReversiBoard
{
private:
	/** The board array      */
	char m_Board[ROWS][COLS];
	/** Column index to place the tile */
	int m_Col;
	/** Row index to place the tile */
	int m_Row;
	/** Computer Score */
	int m_CompScore;
	/** User Score */
	int m_HumanScore;

public:

	friend class ReversiConsoleView; /** ReversiBoard class has a friend class ReversiConsoleView to display the ReversiBoard status*/

	/**Default Constructor to initialise the data members */
	ReversiBoard();

	/** Constructor */
	ReversiBoard(char board [][COLS]);

	/** Destructor */
	virtual ~ReversiBoard();

	/** method to set the board array blank and 4 center tiles to Player and opponent tiles */
	void init_Board(char board[][COLS]);

	/** method to draw the board array 8*8 with desired format */
	void draw_Board();

	/** isMovePossible() Checks to see if the players can make a valid move on the game */
	int isMovePossible(const char board[][COLS], char playerTile);

	/** execute_Move() Makes a move. This places the tile on a disk
	 *  Flips all the opponent's tiles for that move. */
	int execute_Move(char board[][COLS], int row,  int col, char playerTile);

	/** Calculates the score for the current board position for the player */
	void set_CurrPos_Scores(char board[][COLS], int &humanScoreOut, int &compScoreOut);

	/** computer_Move() enables Computer to make a valid move on the board array */
	int makeComputer_Move(char board[][COLS], char playerTile);

	/** calc_Final_Scores() finds the final score for the Computer and Human after all moves were played */
	void calc_Final_Scores();


};

#endif /* REVERSIBOARD_H_ */
