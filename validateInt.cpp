/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is function used for validation of ints
*******************************************************************************/

#include "validateInt.hpp"
#include <iostream>



void validateInt(int i)
{
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();
		std::cout << "\nInvalid Input! Try again!\n";
		std::cin >> i;
	}
}


void validateNum(int i)
{
	while (i < 1 || i > 2)
	{
		std::cout << "Please enter a 1 or 2";
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();
		std::cin >> i;
	}
}
