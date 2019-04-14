/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the menu function
*******************************************************************************/


#include <iostream>
#include "menu.hpp"
#include "validateInt.hpp"




int menu()
{
	int choice;
	


		std::cout << "Welcome to Langton's Ant\n";
		std::cout << "Would you like to:\n\n";
		std::cout << "1. Start Langton's Ant simulation\n";
		std::cout << "2. Quit\n";
		std::cin >> choice;
		validateNum(choice);
		validateInt(choice);
		

		if (choice == 1) //run the simulation
		{
			return 1;
		}

		else if (choice == 2) //exit program
		{
			std::cout << "Goodbye" << std::endl;
			exit(0);
		}
		

	return 1;
}


