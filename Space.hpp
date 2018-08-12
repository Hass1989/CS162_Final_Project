/******************************************************************************
** Program name: Final Project - Space.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Space.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>
#include "Character.hpp"
#include "Protagonist.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:
		Space* top;
		Space* bottom;
		Space* left;
		Space* right;
		string name;	
		int type;
		int key;
	public:
		Space();
		string getName();
		string getType();
		int getKey();
		void linkTop(Space*);
		void linkBot(Space*);
		void linkLeft(Space*);
		void linkRight(Space*);
		virtual void interact(Protagonist &pr);
};

#endif
