/******************************************************************************
** Program name: Final Project - Game.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Game. 
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
#include "Game.hpp"
#include "menu.hpp"
#include "Space.hpp"
#include "Puzzle.hpp"
#include "Store.hpp"
#include "Monster.hpp"
#include "Boss.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Protagonist.hpp"

Game::Game()
{
	cout << "==========The Devil's Office===========\n" << endl;

	cout << "---You are an employee at United Demons Inc..." << endl;
	cout << "---You put out your resignation letter..." << endl;
	cout << "---It was accepted but they still won't give you your soul back..." << endl;
	cout << "---You need to get it back..." << endl;
	cout << "---They took away your access card..." << endl;
	cout << "---So you can't reach the boss..." << endl;
	cout << "---Now you have to defeat an employee and get their access card..." << endl;
	cout << "---Then go and have a chat with the boss...\n" << endl;

	bossDead = false;
		
	//creating space objects, key, name, type
	Puzzle entrance(11,"Entrance");
	Monster monster1(9,"Monster Room 1");
	Store store1(8,"Store Room 1");
	Boss boss(10,"Office of the Demon General Manager");
	Puzzle puzzle3(2,"Puzzle Room 3");
	Puzzle puzzle1(7,"Puzzle Room 1");
	Puzzle puzzle2(6,"Puzzle Room 2");
	Monster monster2(5,"Monster Room 2");
	Monster monster3(1,"Monster Room 3");
	Store store2(4,"Store Room 2");
	Store store3(3,"Store Room 3");

	//Map map;
	/*
 	|	0	|	11	|	0	|
	|	1	|	2	|	3	|
	|	4	|	5	|	6	|
	|	7	|	8	|	9	|
	|	0	|	10	|	0	|
	*/

	//add space to map
	map.addSpace(&monster3); //key 1
	map.addSpace(&puzzle3); //key 2
	map.addSpace(&store3);	//key 3
	map.addSpace(&store2); //key 4
	map.addSpace(&monster2); //key 5
	map.addSpace(&puzzle2); //key 6
	map.addSpace(&puzzle1); //key 7
	map.addSpace(&store1); //key 8
	map.addSpace(&monster1); //key 9
	map.addSpace(&entrance); //key 10
	map.addSpace(&boss); //key 11
	

	//position space in map, format: key, top, bottom, left, right
	map.position(1, 0, 4, 0, 2);
	map.position(2, 11, 5, 1, 3);
	map.position(3, 0, 6, 2, 0);
	map.position(4, 1, 7, 0, 5);
	map.position(5, 2, 8, 4, 6);
	map.position(6, 3, 9, 5, 0);
	map.position(7, 4, 0, 0, 8);
	map.position(8, 2, 10, 7, 9);
	map.position(9, 6, 0, 8, 0);
	map.position(11, 8, 0, 0, 0);
	map.position(10, 0, 2, 0, 0);

	
	//creating protagonist object
	Protagonist prot;


	cout << "---Empower yourself..." << endl;
	prot.levelUp(true);	//choose attributes
	items = {true, false, false};	//initialize items container

	//move from entrance
	cout << "---Where to move?" << endl;
	string dir2 = "North";
	string dir3 = "South";
	string dir4 = "East";
	string dir5 = "West";
	string qui = "Quit";
	string itm = "Check items";

	vector<string>dirs = {dir2, dir3, dir4, dir5};
	
	position = 11;	//entrance space has key 11
	map.print(position);	//print map
	cout << "---You arrived to " << map.getSpace(11)->getName() << endl;
	int dirsMenu = menu(dirs, 1);

	position = 8;	//store 1

	arrive(8);
	cout << "---You have to get a weapon and a shield..." << endl;
	map.getSpace(8)->interact(prot);	//interact with store

	//keep game going as long as there is enough health
	//and the player does not quit
	while ((prot.getHealth() > 0)&&dirs[dirsMenu-1]!="Quit")
	{
		//positions in the middle
		//player is free to move about
		if (position==11||position==8||position==5||position==2)
		{	
		dirs = {dir2, dir3, dir4, dir5, itm, qui};

		dirsMenu = menu(dirs, 6);
		if (dirsMenu==6)
			break;

		//directions that are allowed for movement
		if(dirsMenu==1)
		{
			if (position!=2)
				position-=3;
			else
				position=10;
		}
		else if (dirsMenu==2 && position!=11)
		{
			position+=3;
		}
		else if (dirsMenu==3 && position!=11)
		{
			position+=1;
		}
		else if (dirsMenu==4 && position!=11)
		{
			position-=1;
		}
		else if (dirsMenu==5)
		{
			//check and use items
			checkItems();
			useItems(prot);
		}

		if (dirsMenu!=5 && dirs[dirsMenu-1]!="Quit")
		{
			//move and ineract with new space
			if (position!=10)
			{
			arrive(position);
			map.getSpace(position)->interact(prot);
			}
			
			if (prot.getHealth() <= 0)
			{
				break;
			}
			
			//acquire items if won
			if (position==5 || position==9)
			{
				addItem(2);
			}
			else if (position==2)
			{
				addItem(1);
			}
		}
		}
		else if (position==1||position==4||position==7)
		{
		dirs = {dir2, dir3, dir4, dir5, itm, qui};

		dirsMenu = menu(dirs, 6);
		if (dirsMenu==6)
			break;

		//directions allowed for movement
		if(dirsMenu==1)
		{
			if (position!=1)
				position-=3;
			else if (position==1)
				cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==2)
		{
			if (position!=7)
				position+=3;
			else if (position==7)
				cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==3)
		{
			position+=1;
		}
		else if (dirsMenu==4)
		{
			cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==5)
		{
			checkItems();
			useItems(prot);
		}

			if (dirsMenu!=5 && dirs[dirsMenu-1]!="Quit")
			{
				//arrive and interact with space
				arrive(position);
				map.getSpace(position)->interact(prot);
					
				if (prot.getHealth() <= 0)
				{
					break;
				}

				//get a key (access card) if won
				if (position==1)
					addItem(2);

				
			}
		}

		else if (position==9||position==6||position==3)
		{
		dirs = {dir2, dir3, dir4, dir5, itm, qui};

		dirsMenu = menu(dirs, 6);
		if(dirsMenu==6)
			break;
		
		//directions allowed for movement
		if(dirsMenu==1)
		{
			if (position!=3)
				position-=3;
			else if (position==3)
				cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==2)
		{
			if (position!=9)
				position+=3;
			else if (position==9)
				cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==4)
		{
			position-=1;
		}
		else if (dirsMenu==3)
		{
			cout << "---Blocked route..." << endl;
		}
		else if (dirsMenu==5)
		{
			checkItems();

			useItems(prot);
		}

			if (dirsMenu!=5 && dirs[dirsMenu-1]!="Quit")
			{
				
				arrive(position);
				map.getSpace(position)->interact(prot);

				if (prot.getHealth() <= 0)
				{
					break;
				}
				
	
				//acquire potion or key
				if (position==6)
				{
					addItem(0);
				}
				else if (position==1)
				{
					addItem(2);
				}

				
			}

		}
		
		if (position==10)
		{
			//if you arrive to the boss without a key
			if (items[2]==false)
			{
			cout << "---Ifrit's guards threw you out..." << endl;
			position=8;	//go back to starting position
			arrive(position);
			}
			else
			{
			//if you have a key
			//start the final battle
			cout<<"\n---You used the company access card..." <<endl;
			cout <<"---You can see a demon working in his office..." << endl;
			items[2]=false;
			arrive(position);
			map.getSpace(position)->interact(prot);
			position=2;
			bossDead=true;	//won over the boss
			}
		}

		if (prot.getHealth() <= 0)
		{
			cout << "=====================================" << endl;
			break;
		}
		else if (bossDead)
		{
			//game is won
			cout << "\n\n---Congratulations, you burned all the files at the office..." << endl;
			cout << "---The contract for your soul is gone..." << endl;
			cout << "---Now you are a free man..." << endl;
			cout << "===GAME OVER===" << endl;
			cout << "====================================" << endl;
			break;
		}
	}

}

//adds an item to the item container
void Game::addItem(int key)
{
	//key 0 is a potion
	//key 1 is a magical lamp
	//key 2 is an access key
	if (items[0] && key==0)
	{
		cout << "---You cannot carry more potions..." << endl;
		return;
	}
	else if (items[1] && key==1)
	{
		cout << "---You cannot carry more items..." << endl;
		return;
	}
	else if (items[2] && key==2)
	{
		cout << "---You already have a key..." << endl;
		return;
	}

	if (key >= 0 && key <= 3)
	{
		items[key] = true;
		cout << "---You've acquired an item..." << endl;
		return;
	}
}

//check items in the container
void Game::checkItems()
{

	cout << "---Items in your posession:" << endl;
		
	for (int i=0; i < 3; i++)
	{
		if(items[0] && i==0)
		{
			cout << "-Potion" << endl;	
		}
		else if(items[1] && i==1)
		{
			cout << "-Magical lamp" << endl;
		}
		else if (items[2]&& i==2)
		{
			cout << "- Access Card" << endl;
		}
	}

	cout << "\n";
}

//use items in the container
void Game::useItems(Protagonist &prot)
{
	string exist1 = " - 0";
	string exist2 = " - 0";	


	if (items[0])
	{
		exist1 = " - 1";
	}

	if (items[1])
	{
		exist2 = " - 1";
	}

	cout << "---Use which item: " << endl;
	string it1 = "Potion" + exist1;
	string it2 = "Magical lamp" + exist2;
	string it3 = "None";
	vector<string> itm = {it1, it2, it3};
	
	int menu1 = menu(itm, 3);
	if (menu1==1)
	{
		if (items[0])
		{	//use potion
			prot.recovery();
			items[0]=false;
		}
		else
		{
			cout << "---No potions..." << endl;
		}
	}
	else if(menu1==2)
	{
		if (items[1])
		{
			//use magical lamp and gain extra intelligence
			//this makes your spells stronger
			cout << "---Genie came out of the lamp..." << endl;
			cout << "---Your magical powers are amplified..." << endl;
			prot.setIntel(5);
			items[1]=false;
		}
		else
		{
			cout << "---No lamps..." << endl;
		}

	}
}

//announces the location of the player
void Game::arrive(int pos)
{
	if (pos!=10)
		map.print(pos);

	cout << "---You arrived to " << map.getSpace(pos)->getName() << endl;

	if (pos==10)
	{
		cout << "\nIfrit: YOU DARE TO DEFY ME, MORTAL?!" << endl;
		cout << "Ifrit: YOUR SOUL IS MINE!!" << endl;
	}
}
