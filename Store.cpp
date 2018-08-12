/******************************************************************************
** Program name: Final Project - Store.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Store. 
******************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <vector>
using std::vector;
#include "validation.hpp"
#include "Space.hpp"
#include "Store.hpp"
#include "Protagonist.hpp"
#include "Character.hpp"
#include "menu.hpp"

Store::Store()
{
	key=0;
	type=0;
	name = "";
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

//create store space
Store::Store(int k, string n)
{
	key = k;
	type = 3;	//Store type
	name = n;
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

//interact with store space
void Store::interact(Protagonist &prot)
{
	//displays selections for player
	cout << "---What to buy?" << endl;
	string equ1 = "Weapons";
	string equ2 = "Shields";
	string equ3 = "Level-up";
	string qui = "Nothing";
	vector <string>type = {equ1, equ2, equ3, qui};
	
	string op1 = "Saif     \t- weight: 1 - attack: 2";
	string op2 = "Shamshir \t- weight: 2 - attack: 3";
	string op3 = "Kilij    \t- weight: 3 - attack: 4";
	vector <string>weapons = {op1, op2, op3};
	
	int menu1;
	
	while (menu1!=4)
	{
	menu1 = menu(type,4);
	//buy weapons
	if ((menu1==1) && (prot.getPoints() >= 1))
	{
	int menu2 = menu(weapons, 3);

	prot.weapon(menu2+1);
	prot.carryItem(menu2);
	prot.setSpeed();	//update stats
	prot.stats();
	}
	else if ((menu1==1) && (prot.getPoints() <= 0))
	{
		cout << "---Not enough points..." << endl;
	}
	else if (menu1==2)	//buy shields
	{
		if(prot.getPoints() <= 0)
		{
			cout << "---Not enough points..." << endl;
		}
		else
		{
		string sh1 = "Wooden \t- weight: 1 - defense: 1";
		string sh2 = "Bronze \t- weight: 2 - defense: 2";
		string sh3 = "Steel  \t- weight: 3 - defense: 3";
		vector <string>shields = {sh1, sh2, sh3};

		int menu3 = menu(shields, 3);
		
		//add shield to equipment held
		prot.shield(menu3);
		prot.carryItem(menu3);
		prot.setSpeed();
		prot.stats();
		}
	}
	else if (menu1==3)
	{
		//will randomly level up one attribute
	
		if (prot.getPoints() <= 0)
			cout << "---Not enough points..." << endl;
		else
			{
				int random = rand() % 5 + 1;				

				if (random==1)
					prot.setStamina(5);
				else if (random==2)
					prot.setStrength(5);
				else if (random==3)
					prot.setDefense(5);
				else if (random==4)
					prot.setHealth(5);
				else if (random==5)
					prot.setIntel(5);
			
				//calculate speed based on stamina and carry
				prot.setSpeed();
				prot.losePoint();

				cout << "---A random stat was leveled up" << endl;
			}

		prot.stats();
	}
	}

}
