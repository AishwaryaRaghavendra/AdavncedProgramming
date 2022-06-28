/*
 * ReversiConsoleView.h
 *
 *  Created on: Nov 23, 2020
 *      Author: Aishwarya
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"


class ReversiConsoleView
{
public:
	/** method display_Board() is used to display the Reversi Board in console */
	void display_Board(ReversiBoard *m_ReversiBoard);
	/** method display_Final_Scores() is used to display the Final Scores of the Computer and the Human in console */
	void display_Final_Scores(ReversiBoard *m_ReversiBoard);
};

#endif /* REVERSICONSOLEVIEW_H_ */
