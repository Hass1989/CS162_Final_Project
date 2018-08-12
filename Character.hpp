/******************************************************************************
** Program name: Final Project - Character.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Character
*******************************************************************************/
#include <iostream>
#include <string>
using std::string;
#include <cstdlib>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int health;
		int strength;
		int defense;
		int armor;
		int stamina;
		int intelligence;
		int speed;
		string type;
		int attackDice;
		int defenseDice;
		string name;
	public:
		Character();	
		string getName();
		string getType();
		int getHealth();
		int getArmor();
		virtual int attack() = 0;
		virtual int rollDefense() = 0;
		void setHealth(int);	
		virtual void damage(int);
		unsigned int seed = time(0);
		void recovery();
};

#endif
