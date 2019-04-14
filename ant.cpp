/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the ant class for the langstons ant program
*******************************************************************************/



#include "ant.hpp"
#include "board.hpp"
#include "validateInt.hpp"
#include <iostream>


//CONSTRUCTOR
Ant::Ant(Board *board, int row = 0, int col = 0)
{
	board = board; 
	startRow = row; 
	startColumn = col; 
	orientation = 0; 
}

//Descriptions: This is used to validate input for a char
void Ant::validateAgain(char i)
{
	i = tolower(i);
	while (i != 'y' && i != 'n')
	{
		std::cout << "Invalid input! Try again y/n \n";
		std::cin >> i;
		i = tolower(i);
	}
}

//Sets number of steps the program will run
void Ant::setNumOfSteps()
{
	int row;
	std::cout << "Enter the number of steps\n";
	std::cin >> row;
	validateInt(row);
	numOfSteps = row;
}

int Ant::returnNumOfSteps()
{
	return numOfSteps;
}

//Sets the row the Ant will begin
void Ant::setStartRow()
{
	int row;
	std::cout << "Enter the starting row of the ant\n";
	std::cin >> row;
	validateInt(row);
	startRow = row;
}

void Ant::setRow(int &x)
{
	startRow = x; 
}

int Ant::returnStartRow()
{
	return startRow;
}

//sets the column the ant will begin on 
void Ant::setStartColumn()
{
	int col;
	
	std::cout << "Enter the starting column for the ant\n";
	std::cin >> col;
	validateInt(col);
	
	
	startColumn = col;
}

int Ant::returnStartColumn()
{
	return startColumn;
}

//returns the location of the ant
void Ant::antLocation(int x, int y)
{
	std::cout << "The ants location is: (" << x + 1 << ", " << y +1 << ") " << std::endl; 
}

//Moves ant right
int Ant::moveAntRight(int x, int y)
{
	int move = y + 1; 
	return move; 
}
//moves ant left
int Ant::moveAntDown(int x, int y)
{
	int move = x + 1; 
	return move; 
}
//moves ant left
int Ant::moveAntLeft(int x, int y)
{
	int move = y - 1; 
	return move; 
}

//moves ant up
int Ant::moveAntUp(int x, int y)
{
	int move = x - 1; 
	return move; 
}

//sets the orientation of the ant
void Ant::setOrientation(int x)
{
	orientation = x; 
}

int Ant::getOrientation()
{
	return orientation; 
}








