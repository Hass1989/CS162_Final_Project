/******************************************************************************
** Program name: Final Project - Character.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Character
******************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <ctime>
#include "validation.hpp"
#include "Character.hpp"

//initializes a character
Character::Character()
{
	srand(seed);
}

//causes character to recover some part of health after using potion
void Character::recovery()
{
	double temp = rand() % 5 + 1;

	double rec = 1 + temp / 10;

	cout << name << " recovered " << 2*((health*rec)-health) << " points!"
		<< endl;

	health += 2*((health*rec)-health);
}

string Character::getType()
{
	return type;
}

string Character::getName()
{
	return name;
}

int Character::getHealth()
{
	return health;
}

int Character::getArmor()
{
	return armor;
}

void Character::setHealth(int str)
{
	health = str;	
}

void Character::damage(int dmg)
{
	health -= dmg;
}
