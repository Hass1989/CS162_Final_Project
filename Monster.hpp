/******************************************************************************
** Program name: Final Project - Monster.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Monster.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>
#include "Protagonist.hpp"

#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster : public Space
{
	protected:
		
	public:
		Monster();
		Monster(int k, string n);
		void interact(Protagonist &prot) override;
};

#endif
