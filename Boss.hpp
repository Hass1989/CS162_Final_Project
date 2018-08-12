/******************************************************************************
** Program name: Final Project - Boss.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Boss.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>

#ifndef BOSS_HPP
#define BOSS_HPP

class Boss : public Monster
{
	protected:
		
	public:
		Boss();
		Boss(int k, string n);
};

#endif
