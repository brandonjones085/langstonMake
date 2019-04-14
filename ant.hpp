
/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the header file for the ant class
*******************************************************************************/


#pragma once


#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"

class Board;

class Ant
{
private:
	Board *board;
	int location;
	int orientation;
	int numOfSteps;
	int startRow;
	int startColumn;

public:
	Ant(Board *board, int , int); 
	void validateAgain(char);
	void setNumOfSteps();
	int returnNumOfSteps();
	void setStartRow();
	int returnStartRow();
	void setStartColumn();
	int returnStartColumn(); 
	void antLocation(int, int); 
	void setRow(int&); 
	int moveAntRight(int, int);
	int moveAntDown(int, int); 
	int moveAntLeft(int, int); 
	int moveAntUp(int, int); 
	void setOrientation( int); 
	int getOrientation(); 
};

#endif
