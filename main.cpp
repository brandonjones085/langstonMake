/*******************************************************************************
** Author:       Brandon Jones
** Date:         04/08/2019
** Description:  This is the main file for the langston's ant program
*******************************************************************************/

#include "ant.hpp"
#include "board.hpp"
#include "menu.hpp"
#include <iostream>
#include <iomanip>


int main()
{

	char again = 'y'; //Asks if user would like to repeat the program

	int begin = menu();//Prompts the menu

	while (again == 'y')
	{

		if (begin == 1)
		{
			char **game = NULL; //Pointer to 2D array

			Board *board = NULL; //Pointer to the board object


			Board b(game, 0, 0);//Creates default 
			int count = 0; //How many times the loop will run

			b.setNumOfCols(); //Sets number of Cols in the board
			b.setNumOfRows();//Sets number of rows in the board
			int row = b.getNumOfRows();
			int col = b.getNumOfCols();

			game = b.createArray(); //Creates the 2D array

			board = new Board(game, row, col);//Dynamically creates board


			Ant a(board, 0, 0);//Default ant object


			a.setNumOfSteps();//Number of cycles the program will run

			
			a.setStartColumn();//Column the ant will begin on 
			a.setStartRow(); 
			
			int startCol = a.returnStartColumn();


			int startRow = a.returnStartRow();
			

			int steps = a.returnNumOfSteps();

			Ant ant(board, startRow, startCol);//creates an ant object with all the necessary items
			int orientation = 0;//Direction ant is traveling
			game[startRow][startCol] = '*';

			while (steps > count)
			{
				count++;

				//Checks with space is white or the ant
				if (game[startRow][startCol] == '.' || game[startRow][startCol] == '*')//white spaces
				{

					game[startRow][startCol] = '*';//Assigns the ant value *
					b.printBoard();//Prints board

					a.antLocation(startRow, startCol);//assigns the location of ant

					std::cout << "The step: " << count << std::endl;

					orientation = a.getOrientation();//The direction ant is heading


					//This will run if the spaces are white, turn the ant right, and turn the space black

					if (orientation == 0)
					{
						//Ant moves right and space is white
						
						int borderCol = b.getNumOfCols() -1 ;

						if (startCol == (borderCol))//Checks for the border
						{

							startCol = 0;//moves ant to other side of board
							startCol = a.moveAntRight(startRow, startCol -1);
							//Ant moves right and space is white

							b.changeToBlack(startRow, (borderCol));//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 3;
								a.setOrientation(orientation);
							}
							else
							{
								//If the space it moves to is black, the orientation will change
								orientation = 1;
								a.setOrientation(orientation);
							}

						}
						else //Not border
						{
							startCol = a.moveAntRight(startRow, startCol);
							b.changeToBlack(startRow, startCol-1);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 3;
								a.setOrientation(orientation);
							}
							else
							{
								//If the space it moves to is black, the orientation will change
								orientation = 1;
								a.setOrientation(orientation);
							}

						}
					}
					else if (orientation == 1)
					{
						//Ant moves up and space is white
						
						int borderRow = b.getNumOfRows() - 1;

						if (startRow == 0)//Checks for border
						{
							startRow = borderRow;
							startRow = a.moveAntUp(startRow+1, startCol);

							b.changeToBlack(0, startCol);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 0;
								a.setOrientation(orientation);
							}
							else
							{
								//If the space ant moves to is black
								
								orientation = 0;
								a.setOrientation(orientation);
							}
						}
						else
						{
							startRow = a.moveAntUp(startRow, startCol);
							b.changeToBlack(startRow + 1, startCol);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 0;
								a.setOrientation(orientation);
							}
							else
							{
								//If the space ant moves to is black
								orientation = 0;
								a.setOrientation(orientation);
							}
						}
					}
					else if (orientation == 2)
					{

						int borderCol = b.getNumOfCols();

						if ((startCol) == 0) //This will run if it's on the border
						{
							startCol = borderCol-1;

							//Ant moves left and space is white
							startCol = a.moveAntLeft(startRow, startCol +1);

							b.changeToBlack(startRow, 0);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 1;
								a.setOrientation(orientation);
							}
							else
							{
								//If space ant moves to is black
								orientation = 3;
								a.setOrientation(orientation);
							}

						}
						else
						{

							//Ant moves left and space is white
							startCol = a.moveAntLeft(startRow, startCol);
							b.changeToBlack(startRow, startCol + 1);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 1;
								a.setOrientation(orientation);
							}
							else
							{
								//If space ant moves to is black
								orientation = 3;
								a.setOrientation(orientation);
							}
						}


					}
					else if (orientation == 3)
					{
						//Ant moves down and space is white
						



						int borderRow = b.getNumOfRows()-1;

						if (startRow == borderRow)
						{
							startRow = 0;
							startRow = a.moveAntDown(startRow-1, startCol);

							b.changeToBlack(borderRow, startCol);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 2;
								a.setOrientation(orientation);
							}
							else
							{
								//space ant moves to is black
								orientation = 2;
								a.setOrientation(orientation);
							}



						}
						else
						{
							startRow = a.moveAntDown(startRow, startCol);
							b.changeToBlack(startRow - 1, startCol);//Changes the space to black

							if (game[startRow][startCol] == '.')
							{
								orientation = 2;
								a.setOrientation(orientation);
							}
							else
							{
								//space ant moves to is black
								orientation = 2;
								a.setOrientation(orientation);
							}

						}




					}


				}
				else   //This will run if the color is already black
				{

					game[startRow][startCol] = '*';//Assigns the ant value *
					b.printBoard();//Prints the board

					a.antLocation(startRow, startCol);//Assigns the location

					std::cout << "The step: " << count << std::endl;

					orientation = a.getOrientation();//returns the orientation the ant is moving


					if (orientation == 0)//ANT MOVES LEFT
					{	
						int borderCol = b.getNumOfCols(); 
						if (startCol == 0)
						{
							startCol = borderCol -1; 
							startCol = a.moveAntLeft(startRow, startCol);

							b.changeToWhite(startRow, 0);//Changes the space to black


							if (game[startRow][startCol] == '#')
							{
								orientation = 3;
								a.setOrientation(orientation);
							}
							else
							{
								//If space ant moves to is white
								orientation = 1;
								a.setOrientation(orientation);
							}

						}
						else
						{
							//Ant moves left
							startCol = a.moveAntLeft(startRow, startCol);
							b.changeToWhite(startRow, startCol + 1);//Changes the space to white

							if (game[startRow][startCol] == '#')
							{
								orientation = 3;
								a.setOrientation(orientation);
							}
							else
							{
								//If space ant moves to is white
								orientation = 1;
								a.setOrientation(orientation);
							}

						}
						


					}
					else if (orientation == 1)//ANT MOVES UP
					{
						int borderRow = b.getNumOfRows() - 1; 

						if (startRow == 0)//checks for border
						{
							startRow = borderRow; 
							startRow = a.moveAntUp(startRow + 1, startCol); 
							b.changeToBlack(0, startCol); 

							if (game[startRow][startCol] == '#')
							{
								orientation = 0;
								a.setOrientation(orientation);
							}
							else
							{
								//if space ant moves to is white
								orientation = 0;
								a.setOrientation(orientation);
							}




						}
						else
						{
							//Ant moves up
							startRow = a.moveAntUp(startRow, startCol);
							b.changeToWhite(startRow + 1, startCol);//changes space to white


							if (game[startRow][startCol] == '#')
							{
								orientation = 0;
								a.setOrientation(orientation);
							}
							else
							{
								//if space ant moves to is white
								orientation = 0;
								a.setOrientation(orientation);
							}

						}

						
					}
					else if (orientation == 2)//ANT MOVES RIGHT
					{
						
						int borderCol = b.getNumOfCols() -1; 

						if (startCol == borderCol)//checks for border
						{
							startCol = 0; 
							startCol = a.moveAntRight(startRow, startCol-1);
							b.changeToWhite(startRow, borderCol);//


							if (game[startRow][startCol] == '#')
							{
								orientation = 1;
								a.setOrientation(orientation);
							}
							else
							{
								//if space ant moves to is white
								orientation = 3;
								a.setOrientation(orientation);
							}

						}
						else
						{

							//Ant moves right
							startCol = a.moveAntRight(startRow, startCol);
							b.changeToWhite(startRow, startCol - 1);//changes space to white

							if (game[startRow][startCol] == '#')
							{
								orientation = 1;
								a.setOrientation(orientation);
							}
							else
							{
								//if space ant moves to is white
								orientation = 3;
								a.setOrientation(orientation);
							}
						}



					}
					else if (orientation == 3)//ANT MOVE DOWN
					{
					int borderRow = b.getNumOfRows() - 1; 
					if (startRow == borderRow)//checks for border
					{
						startRow = 0; 
						startRow = a.moveAntDown(startRow - 1, startCol); 

						b.changeToBlack(borderRow, startCol); 

						if (game[startRow][startCol] == '#')
						{
							orientation = 2;
							a.setOrientation(orientation);
						}
						else
						{
							//If space ant moves to is white
							orientation = 2;
							a.setOrientation(orientation);
						}


					}
					else
					{
						//Ant moves down
						startRow = a.moveAntDown(startRow, startCol);
						b.changeToWhite(startRow - 1, startCol);


						if (game[startRow][startCol] == '#')
						{
							orientation = 2;
							a.setOrientation(orientation);
						}
						else
						{
							//If space ant moves to is white
							orientation = 2;
							a.setOrientation(orientation);
						}
					}

						
					}

				}
				


			}
			delete [] board;
			
			for(int i = 0; i<row; i++)
			{
				delete[] game[i];
			}	
			delete [] game;	

			std::cout << "Would you like to play again?\n";
			std::cin >> again;//Resets the again variable


		}
		

	}
	std::cout << "\nGoodbye!\n";
	return 0;
}
