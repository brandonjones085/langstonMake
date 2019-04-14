/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the header file for the board class
*******************************************************************************/



#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP
#include "ant.hpp"

class Ant;

class Board
{
private:
	int numOfCols;
	int numOfRows;
	char **charArray;

public:
	Board(char **charArray, int, int); 
	void setNumOfCols();
	int getNumOfCols();
	void setNumOfRows();
	int getNumOfRows();
	char **createArray(); 
	void printBoard(); 
	void changeToBlack(int, int);
	void changeToWhite(int, int); 
	

};

#endif
