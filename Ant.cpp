/******************************************************************
 * Program Name: Langton's Ant
 * Author: Gabriel Rice
 * Date: 4/13/18
 * Description: Ant.cpp
 * This is the implementation file for the Ant class
 * ***************************************************************/
#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

Ant::Ant(char** antArray, int startRow, int startCol, int numRows, int numCols)
{
	direction = UP;//default direction (ant starts facing up)
	x = startRow;//ant start column
	y = startCol;//ant start row
	height = numRows;
	width = numCols;

	//Initialize board to empty spaces
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			antArray[row][col] = ' ';
		}
	}
}

/************************************************************************
 * Description: This function describes the ants behavior for turning
 * right.
 * *********************************************************************/
void Ant::antRight()
{
	switch (direction)
	{
		case UP: direction = RIGHT;
			break;
		case RIGHT: direction = DOWN;
			break;
		case DOWN: direction = LEFT;
			break;
		case LEFT: direction = UP;
			break;
	}
}

/***********************************************************************
 * Description: This function describes the ants behavior for turning
 * left.
 * ********************************************************************/
void Ant::antLeft()
{
	switch (direction)
	{
		case UP: direction = LEFT;
			break;
		case LEFT: direction = DOWN;
			break;
		case DOWN: direction = RIGHT;
			break;
		case RIGHT: direction = UP;
			break;
	}
}

/***********************************************************************
 * Description: This function describes the ants behavior for forward
 * movement based off of direction.
 * ********************************************************************/
void Ant::antForward()
{

	if (direction == UP)
	{
		y -= 1;
	}

	else if (direction == RIGHT)
	{
		x += 1;
	}

	else if (direction == DOWN)
	{
		y += 1;
	}

	else if (direction == LEFT)
	{
		x -= 1;
	}

	//Consider edge cases
	if (x > width)
	{
		x = 0;
	}
	
	else if (x < 0)
	{
		x = width - 1;
	}

	if (y > height)
	{
		y = 0;
	}

	else if (y < 0)
	{
		y = height - 1;
	}
}
			
/*********************************************************************
 * Description: This function implements the above functions and 
 * determines behavior based on whether it is on a ' ' or '#'.
 * ******************************************************************/
void Ant::moveAnt(char** antArray)
{

	if (antArray[x][y] == ' ')
	{
		antRight();
		antArray[x][y] = '#';
		antForward();
	}

	else if (antArray[x][y] == '#')
	{
		antLeft();
		antArray[x][y] = ' ';
		antForward();
	}

	//Description of how ant behaves in program
	cout << "x = " << x << " y = " << y << " dir = " << direction << endl;
	cout << "-------------------------------------------------" << endl;

	//call to print board
	printBoard(antArray);
}

/*********************************************************************
 * Description: This function prints the ant (*) to the board.
 * ******************************************************************/
void Ant::printBoard(char** antArray)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == y && j == x)
			{
				cout << '*';
			}

			else
				cout << antArray[i][j];
		}	
		cout << endl;
	}		
}
