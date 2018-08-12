/******************************************************************************
** Program name: Final Project - Space.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Space. 
******************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <ctime>
#include "validation.hpp"
#include "Space.hpp"
#include "menu.hpp"

Space::Space()
{
/*
	key=0;
	type=0;
	name = "";
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
*/
}

/*
Space::Space(int k, string n, int t)
{
	key = k;
	type = t;
	name = n;
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}
*/

void Space::interact(Protagonist &pr)
{

}

string Space::getName()
{
	return name;
}

string Space::getType()
{
	switch(type)
	{
		case 1:
			return "Puzzle";
		case 2:
			return "Monster";
		case 3:
			return "Store";
		case 4:
			return "Boss";
		default:
			return "Invalid";
	}
}

int Space::getKey()
{
	return key;
}

void Space::linkTop(Space* t)
{
	top = t;
}

void Space::linkBot(Space* b)
{
	bottom = b;
}

void Space::linkLeft(Space* l)
{
	left = l;
}

void Space::linkRight(Space* r)
{
	right = r;
}
