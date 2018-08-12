/******************************************************************************
** Program name: Final Project - Protagonist.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Protagonist
*******************************************************************************/
#include <iostream>
#include <string>
using std::string;
#include <cstdlib>
#include "Character.hpp"

#ifndef PROTAGONIST_HPP
#define PROTAGONIST_HPP

class Protagonist : public Character
{
	protected:
		int points;
		int weight;
		int carry;
		int shield1;
		int weapon1;
	public:
		Protagonist();
		void setStamina(int);
		void setStrength(int);
		void setDefense(int);
		void setIntel(int);
		void setSpeed();
		int getSpeed();
		int spell();
		void setHealth(int);
		int getPoints();
		void losePoint();
		void gainPoint();
		void carryItem(int);
		void levelUp(bool start);
		void stats();
		void weapon(int);
		void shield(int);
		int attack() override;
		int rollDefense() override;
		void damage(int) override;
};

#endif
