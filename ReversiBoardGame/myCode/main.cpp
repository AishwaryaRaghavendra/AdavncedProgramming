// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required
#include <string>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main (void)
{
	// TODO: Add your program code here
	cout << "Lab1_1_Reversi started." << endl << endl;

	char board [ROWS][COLS] = { 0 };  /** The board           */
	int row_Index = 0;                      /** Board row index     */
	int col_Index = 0;                      /** Board column index  */
	int game_Count = 0;              /** Number of games     */
	int moves_Count = 0;              /** Count of valid Moves      */
	char retry = 0;                   /** Replay Game choice input */
	int player_Type = 0;                /** Player indicator    */
	int flips_Human = 0; 			 /** count of Flips done by Human */
	int flips_Computer = 0; 	 /** count of Flips done by Computer */
	int no_Moves = 0; 			/** No Possible moves */

	cout << "REVERSI" << endl;


	ReversiBoard *m_ReversiBoard = new ReversiBoard(board);
	ReversiConsoleView m_reversiConsoleView;

	do
	{
		/* On even games the player starts; */
		/* on odd games the computer starts */
		player_Type = ++game_Count % 2;
		moves_Count = 4;                /* Starts with four counters */

		m_ReversiBoard->init_Board(board); /** to initialise the board with four tiles at center */

		/** The game play loop */
		do
		{
			m_reversiConsoleView.display_Board(m_ReversiBoard); /** Display the board  */

			if(player_Type++ % 2)
			{
				/**   It is the player's turn                    */
				if(m_ReversiBoard->isMovePossible(board, HUMAN))
				{
					/** Read player moves until a valid move is entered */
					while(1)
					{
						fflush(stdin);
						cout << "Please enter Row " << endl;
						cin >> row_Index;
						cout << row_Index << endl;
						cout << "Please enter Column " << endl;
						cin >> col_Index;
						cout << col_Index << endl;

						if( row_Index >= 0 && col_Index >= 0 && row_Index < ROWS && col_Index < COLS)
						{
							flips_Human = m_ReversiBoard->execute_Move(board, row_Index, col_Index, HUMAN); /** Execute the valid Human Move */
							no_Moves = 0; /** reset to zero for possible move */
							moves_Count++;              /* Increment move count */
							cout << "You have flipped " << flips_Human << " discs." << endl;
							break;
						}
						else
						{
							cout << "Invalid move for the given row and column, please try again with valid row and col." << endl;
						}
					}
				}
				else     /** No valid moves */
				{
					if (flips_Human == 0)
					{  ++no_Moves;
					cout << "No possible moves left. You have to pass, enter 'Pass' " << endl;
					cin>> retry;
					}
					else
					{
						cout << "Neither of us can move, so the Game is Over." << endl;
					}
				}
			}
			else
			{
				/** It is the computer's turn                    */
				if(m_ReversiBoard->isMovePossible(board, COMPUTER)) /** Check for valid moves */
				{
					flips_Computer = m_ReversiBoard->makeComputer_Move(board, COMPUTER); /** Execute the valid Human Move */
					no_Moves = 0; /** reset to zero for possible move */
					moves_Count++;  /* Increment move count */
					cout << "Computer has Flipped " << flips_Computer << " discs." << endl;
					break;
				}
				else
				{
					if(flips_Computer == 0)
					{
						++no_Moves; /** Preincrement the no Moves variable to track no valid moves */
						cout << "No possible moves left. I have to pass " << endl;
					}
					else
					{
						cout << "Neither of us can move, so the Game is Over." << endl;
					}
				}
			}

		}while(moves_Count < ROWS*COLS && no_Moves < 2);  /** Repeat until all 8*8 disks are occupied */

		/* Game is over */
		m_reversiConsoleView.display_Board(m_ReversiBoard); /** Display the final board  */
		m_reversiConsoleView.display_Final_Scores(m_ReversiBoard);  /** Display the final scores  */

		cout << "Do you want to play again (y/n): "<< endl;
		cin>> retry;         /** Get y or n             */
	}while(tolower(retry) == 'y'); /** Play again on y          */

	return 0;
}


