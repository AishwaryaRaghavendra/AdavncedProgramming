/*
 * ReversiConsoleView.cpp
 *
 *  Created on: Nov 23, 2020
 *      Author: Aishwarya
 */


#include <iostream>
#include <stdlib.h>
//#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
using namespace std;


 /** display_Board(): to display the Reversi Board status after a move */
void ReversiConsoleView::display_Board(ReversiBoard *m_ReversiBoard)
{
	m_ReversiBoard->draw_Board();
}


/** method display_Final_Scores() to display the Final Scores of the Player and Computer
 *@param   */
void ReversiConsoleView::display_Final_Scores(ReversiBoard *m_ReversiBoard)
{

	m_ReversiBoard->calc_Final_Scores();

}

