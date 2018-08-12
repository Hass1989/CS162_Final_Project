/******************************************************************************
** Program name: Final Project - Monster.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Monster. 
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
#include "Monster.hpp"
#include "Protagonist.hpp"
#include "Character.hpp"
#include "menu.hpp"

Monster::Monster()
{
	key=0;
	type=0;
	name = "";
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

Monster::Monster(int k, string n)
{
	key = k;
	type = 2;	//Monster type
	name = n;
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

//fight with the monster
void Monster::interact(Protagonist &prot)
{
	cout << "---A monster appears..." << endl;
	string sel1 = "Attack";
	string sel2 = "Defend";
	string sel3 = "Magic";

	vector<string>sel = {sel1, sel2, sel3};
	int menu1;	

	//monster attributes
	int health = rand() % 20 + 10;
	int strength = rand() % 10 + 5;
	int defense = rand() % 10 + 5;
	int speed = rand() % 30 + 10;

	int playerdefense;

	//simulate the fight
	while (prot.getHealth()>0 && health>0)
	{
		menu1 = menu(sel, 3);
		
		playerdefense = prot.rollDefense();
		if (menu1==1)
		{
			int temp = prot.attack() - defense/2;
			cout << "---Player attacks..." << endl;
			cout << "---Player dealt " << temp << " in damage..." << endl;
			health-=temp;
		}
		else if(menu1==2) //use shield to defend yourself
		{
			playerdefense+= 5;
			prot.setIntel(2); //intelligence gets higher
			cout << "---Player defense..." << endl;
			
		}
		else if(menu1==3) //use magic
		{
			int temp = prot.spell() - defense/2;
			cout << "---Player chants spell..." << endl;
			cout << "---Player dealt " << temp << " in damage..." << endl;
			health-=temp;
		}

		cout << "---Monster attacks..." << endl;
		cout << "---Player takes " << strength - playerdefense/3 << " in damage..." << endl;
		prot.damage(strength - playerdefense/3);
		
		//if the monster is faster than player
		//it will attack twice
		if (speed >= 1.25*prot.getSpeed())
		{
			int temp = 1;

			if ((strength - playerdefense) <= 0)
			{
				temp = 1;
			}
			else
			{
				temp = strength - playerdefense;
			}
	
			cout << "---The monster is very fast..." << endl;
			cout << "---Monster attacks again..." << endl;
			cout << "---Player takes " << temp << " in damage..." << endl;
			prot.damage(temp);
		}
		
		//in case of health dipping to zero or below
		if (prot.getHealth() <= 0)
		{
			cout << "\n---You are dead..." << endl;
			cout << "===GAME OVER===" << endl;
			break;
		}
		else if (health <= 0) //in case monster's health is zero
		{
			cout << "---The monster is dead..." << endl;
			break;
		}

		prot.stats();
	}

}
