/******************************************************************************
** Program name: Final Project - Puzzle.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Puzzle.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>
#include "Protagonist.hpp"

#ifndef PUZZLE_HPP
#define PUZZLE_HPP

class Puzzle : public Space
{
	protected:
		
	public:
		Puzzle();
		Puzzle(int k, string n);
		void interact(Protagonist &pr) override;
};

#endif
