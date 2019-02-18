//Testing area for langton's ant
#include <iostream>
#include "Ant.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Menu m;	

	//Call menu function to start simulation
	m.getUserInput();
	
	//Get user input from Menu
	int numRows = m.getNumRows();
	int numCols = m.getNumCols();
	int startRow = m.getStartRow();
	int startCol = m.getStartCol();
	int numSteps = m.getNumSteps();

	//Dynamically allocate a 2d array with Menu info
	char **antArray = new char*[numRows];
		for (int row = 0; row < numRows; row++)
		{	
			antArray[row] = new char[numCols];
		}

	//create ant obj
	Ant a(antArray, startRow, startCol, numRows, numCols);

	//Print initial board and position of ant
	a.printBoard(antArray);

	//Call moveAnt function and loop it to print ant behavior
	for (int step = 0; step < numSteps; step++)
	{
		a.moveAnt(antArray);
	}	

	//Return memory back to heap
	for (int i = 0; i < numRows; i++)
	{
		delete [] antArray[i];
	}
	delete [] antArray;
	
	return 0;
}
	
