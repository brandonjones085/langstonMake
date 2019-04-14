/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the board class for the langstons ant program
*******************************************************************************/




#include "board.hpp"
#include "ant.hpp"
#include "validateInt.hpp"
#include <iostream>
#include <iomanip>

//CONSTRUCTOR
Board::Board(char **charArray, int rows, int cols)
{
	
	numOfRows = rows; 
	numOfCols = cols; 

	charArray = new char *[rows]; 
	for (int i = 0; i < rows; i++)
	{
		charArray[rows] = new char[cols]; 
	}

}

//Creates the pointer to 2d array
char **Board::createArray()
{
	int row = getNumOfRows(); 
	int col = getNumOfCols(); 

	charArray = new char*[row]; 
	for (int i = 0; i < row; i++)
	{
		charArray[i] = new char[col]; 
		for (int j = 0; j < col; j++)
		{
			charArray[i][j] = '.'; 
		}
 
	}

	return charArray; 
}

//Prints the board
void Board::printBoard()
{
	//Prints the board
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfCols; j++)
		{
			std::cout << charArray[i][j];
		}

		std::cout << std::endl;
	}
}

int Board::getNumOfCols()
{
	return numOfCols;
}

//Sets the number of columns for the board
void Board::setNumOfCols()
{
	int col;
	std::cout << "Enter the number of columns for the board\n";
	std::cin >> col;
	validateInt(col);
	numOfCols = col;
}

//Sets the number of rows for the board
void Board::setNumOfRows()
{
	int i;

	std::cout << "Enter the number of rows for the board\n";
	std::cin >> i;
	validateInt(i);
	numOfRows = i;
}

int Board::getNumOfRows()
{
	return numOfRows;
}


//Changes the space to black 
void Board::changeToBlack(int x, int y)

{
	if (charArray[x][y] == '.' || charArray[x][y] == '*')
	{
		charArray[x][y] = '#';	 
	}
	else if (charArray[x][y] == '#')
	{
		charArray[x][y] = '.'; 
	}
	

}

//Changes the space to white
void Board::changeToWhite(int x, int y)
{
	if (charArray[x][y] == '#' || charArray[x][y] == '*')
	{
		charArray[x][y] = '.';
	}
}



























