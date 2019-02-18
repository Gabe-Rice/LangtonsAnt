/**********************************************************************
 * Program Name: Langston's Ant
 * Author: Gabriel Rice
 * Date: 4/10/18
 * Description: Menu.cpp
 * This is the implementation file for the Menu class.
 * ********************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

Menu::Menu()
{
	startSim = 0;
	numRows = 0;
	numCols = 0;
	numSteps = 0;
	startRow = 0;
	startCol = 0;
	playAgain = 0;
}

/**********************************************************************
 * Description: This function gathers the user data to input the 
 * initial size of board and coordinates of ant. The input validation
 * attempts to ensure that only positive integers that are within the 
 * specified size of the array are inputted.
 * *******************************************************************/
void Menu::getUserInput()
{
	//Initial prompt
	cout << "\n  1.  Start Langton's Ant Simulation" << endl;
	cout << "  2.  Quit\n" << endl;
	cin >> startSim;

	//input validation to ensure either 1 or 2 are entered
	while (!(startSim == 1 || startSim == 2))
	{
		cout << "Invalid Choice\n" << endl;
		cout << "  1.  Start Simulation" << endl;
		cout << "  2.  Quit" << endl;

		//input validation to ensure only int is entered
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> startSim;
	}

	if (startSim == 1)
	{
	
		cout << "\nEnter integers for the following:" << endl;

		while (cout << "\nThe number of rows for the board: " && 
			(!(cin >> numRows) || numRows < 0))
		{
			cout << "Enter a positive integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (cout << "\nThe number of columns for the board: " &&
			(!(cin >> numCols) || numCols < 0))
		{
			cout << "Enter a positive integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		
		while (cout << "\nThe number of steps for the ant to take: " &&
			(!(cin >> numSteps) || numSteps < 0))
		{
			cout << "Enter a positive integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (cout << "\nThe starting row for the ant: " &&
			(!(cin >> startRow) || (startRow < 0) || (startRow > 
			 numRows)))
		{
			cout << "Enter a positive integer that is " <<
				 numRows << " or less\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		while (cout << "\nThe starting column for the ant: " &&
			(!(cin >> startCol) || (startCol < 0) || (startCol > 
			 numCols)))
		{
			cout << "Enter a positive integer that is " << 
				 numCols << " or less\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	}
}

/*************************************************************************
 * Description: When called, this function prompts the user to play the
 * simulation again or quit. It also uses input validation to ensure
 * positive integer is inputted.
 * *********************************************************************/ 
void Menu::repeatSim()
{
	cout << "\n  1.  Play Again" << endl;
	cout << "  2.  Quit\n" << endl;
	cin >> playAgain;

	//input validation to ensure either 1 or 2 are entered
	while (!(playAgain == 1 || playAgain == 2))
	{
		cout << "Invalid Choice\n" << endl;
		cout << "  1.  Play Again" << endl;
		cout << "  2.  Quit" << endl;

		//input validation to ensure only int is entered
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> playAgain;
	}

	if (playAgain == 1)
	{
		getUserInput();
	}
}

int Menu::getStartSim()
{
	return startSim;
}

int Menu::getNumRows()
{
	return numRows;
}

int Menu::getNumCols()
{
	return numCols;
}

int Menu::getNumSteps()
{
	return numSteps;
}

int Menu::getStartRow()
{
	return startRow;
}

int Menu::getStartCol()
{
	return startCol;
}

int Menu::getPlayAgain()
{
	return playAgain;
}
