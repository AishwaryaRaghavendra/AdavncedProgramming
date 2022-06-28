// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Board.h"
#include "ConsoleView.h"

// Main program
int main (void)
{

	std::cout << "BattleshipGame started." << std::endl << std::endl;

	std::cout<<"Part-1 Tests for Basic Classes:"<<std::endl;
	void part1tests();
	part1tests();
	std::cout<<std::endl;

	std::cout<<"Part-2 Tests for Display and Arrangement Rules:";
	void part2tests();
	part2tests();
	std::cout<<std::endl;

	std::cout<<"Part3 Tests for Shots:";
	void part3tests();
	part3tests();
	std::cout<<std::endl;

	return 0;
}
