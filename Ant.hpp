/*********************************************************************
 * Program Name: Langton's Ant
 * Author: Gabriel Rice
 * Date: 4/13/18
 * Description: Ant.hpp
 * This is the header file for the Ant class
 * ******************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Menu.hpp"

class Ant
{
	enum Orientation { UP, RIGHT, DOWN, LEFT };

	private:
		 
		Orientation direction;
		int x;
		int y;
		int height;
		int width;
	public:
		Ant(char**, int, int, int, int);
		void antForward();
		void antRight();
		void antLeft();
		void moveAnt(char **);
		void printBoard(char**);
};
#endif
