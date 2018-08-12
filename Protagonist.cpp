/******************************************************************************
** Program name: Final Project - Protagonist.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Protagonist
******************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <ctime>
#include <vector>
using std::vector;
#include "validation.hpp"
#include "menu.hpp"
#include "Character.hpp"
#include "Protagonist.hpp"

//initializes a player character
Protagonist::Protagonist()
{
	srand(seed);
	points = 20;
	weight = 0;
	stamina = 0;
	defense = 1;
	strength = 1;
	health = 10;
	intelligence = 1;
	speed = 1;
	weapon1 = 0;
	shield1 = 0;
}

void Protagonist::setStamina(int st)
{
	stamina += st;
}

void Protagonist::setStrength(int str)
{
	strength += str;
}

void Protagonist::setDefense(int def)
{
	defense += def;
}

void Protagonist::setHealth(int hel)
{
	health +=hel;
}

void Protagonist::setIntel(int intel)
{
	intelligence += intel;
}

//items carried affect weight and speed
void Protagonist::carryItem(int c)
{
	weight += c;

}

//speed is calculated based on stamina and weight
void Protagonist::setSpeed()
{
	speed = (stamina - (weight)) * 2;
}

//level up attributes
void Protagonist::levelUp(bool start)
{
	string op1 = "Stamina";
	string op2 = "Strength";
	string op3 = "Defense";
	string op4 = "Health";
	string op5 = "Intelligence";
	string op6;
	
	if (start)	//beginning of game only
	{
		op6 = "Use pre-set characters";
	}
	else
	{
		op6 = "Quit";
	}

	vector<string>options = {op1, op2, op3, op4, op5, op6};
	
	int menu1;
	
	cout << "---Select stat to level up: " << endl;
	menu1 = menu(options, 6);

	if (menu1==6 && op6=="Quit")
	{
		return;
	}
	else if (menu1!=6 && op6!="Quit")
	{
	if (points > 0)	//as long as there are enough points
	{
		int p = 1;
		if (start)
		{
			p = 10;
		}

		while (p>0)
		{
		if (menu1==1)
			setStamina(5);
		else if (menu1==2)
			setStrength(5);
		else if (menu1==3)
			setDefense(5);
		else if (menu1==4)
			setHealth(5);
		else if (menu1==5)
			setIntel(5);
			
		points--;
		p--;
	
		setSpeed();
		stats();

		if (p>0)
		{
			menu1 = menu(options, 5);
		}
		}
	}
	else
	{
		cout << "---Not enough points..." << endl;
	}
	}
	else if (menu1==6)
	{
		//pre-set characters
		string op1 = "Sorcerer";
		string op2 = "Soldier";
		vector<string> options2 = {op1, op2};
		
		int menu2 = menu(options2, 2);

		if (menu2==1)
		{
			setStamina(15);
			setStrength(0);
			setDefense(5);
			setHealth(10);
			setIntel(20);	

			points=10;
		}
		else if (menu2==2)
		{	
			setStamina(15);
			setStrength(15);
			setDefense(10);
			setHealth(10);
			setIntel(0);

			points=10;
		}

		setSpeed();
		stats();
	}
}

//decrement points by one
void Protagonist::losePoint()
{
	if (points > 0)
	{
		points--;
	}
	else
	{
		cout << "--Out of points..." << endl;
	}
}

void Protagonist::gainPoint()
{
	points++;
}

//displays stats of the player character
void Protagonist::stats()
{
	cout << "Stamina: " << stamina << endl;
	cout << "Strength: " << strength << endl;
	cout << "Defense: " << defense << endl;
	cout << "Intelligence: " << intelligence << endl;
	cout << "Health: " << health << endl;
	cout << "Speed: " << speed << endl;
	cout << "Weapon: " << weapon1 << endl;
	cout << "Shield: " << shield1 << endl;
	cout << "Carry: " << weight << endl;
	cout << "Points left: " << points << "\n" << endl;
}

int Protagonist::attack()
{
	
	return rand() % strength + (strength/2) + (weapon1);

}

//magic attack
int Protagonist::spell()
{
	return rand() % intelligence + (intelligence/2) + (weapon1);
}

int Protagonist::rollDefense()
{
	return rand() % defense + (shield1*2);
}

int Protagonist::getSpeed()
{
	return speed;
}

//equipt weapon for character
void Protagonist::weapon(int wp)
{
	if (points-wp >= 0)
	{
		weapon1 = wp;
		points-=wp;
	}
	else
	{
		weapon1 = points;
		points = 0;
		cout << "---You get what you pay for..." << endl;
	}
}

//equip shield
void Protagonist::shield(int sh)
{
	if (points-sh >= 0)
	{
		shield1 = sh;
		points-=sh;
	}
	else
	{
		shield1 = points;
		points = 0;
		cout << "---You get what you pay for..." << endl;
	}
}

int Protagonist::getPoints()
{
	return points;
}

//sustain damage
void Protagonist::damage(int dmg)
{
	health -=dmg;
}
