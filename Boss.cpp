/******************************************************************************
** Program name: Final Project - Boss.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Boss. 
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
#include "Monster.hpp"
#include "Boss.hpp"
#include "menu.hpp"

Boss::Boss()
{
	key=0;
	type=0;
	name = "";
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

Boss::Boss(int k, string n)
{
	key = k;
	type = 4;	//Boss type
	name = n;
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}


