/**********************************************************************
 * Program Name: Langston's Ant
 * Author: Gabriel Rice
 * Description: Menu.hpp
 * This is the header file for the Menu class.
 * *******************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
	private:
		int startSim, numRows, numCols, numSteps, startRow, 
		    startCol, playAgain;

	public:
		Menu();
		void getUserInput();
		void repeatSim();
		int getStartSim();
		int getNumRows();
		int getNumCols();
		int getNumSteps();
		int getStartRow();
		int getStartCol();
		int getPlayAgain();
};
#endif	
