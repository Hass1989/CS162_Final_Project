/******************************************************************************
** Program name: Final Project - Puzzle.cpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: The implementations of the class Puzzle. 
******************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <ctime>
#include <vector>
using std::vector;
#include "validation.hpp"
#include "Space.hpp"
#include "Puzzle.hpp"
#include "menu.hpp"

Puzzle::Puzzle()
{
	key=0;
	type=0;
	name = "";
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

Puzzle::Puzzle(int k, string n)
{
	key = k;
	type = 1;	//puzzle type
	name = n;
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

//interact with the puzzle room
void Puzzle::interact(Protagonist &prot)
{
	//scenario from Monty Python and the Holy Grail
		string temp;
	
		cout << "\n---You have entered a puzzle room..." << endl
			<< "---You see a ghost of an old man..." << endl
			<< "Old Man: In order to pass, you have to"
			<< " answer my questions.\n" << endl;

		cout << "Old Man: What is your name?" << endl;
		getline(cin, temp);
		cout << "Old Man: What is your quest?" << endl;
		getline(cin, temp);

		cout << "Old Man: What is the airspeed velocity of an" 
			<< " unladed swallow?" << endl;

		string ans1 = "15 meters per second";
		string ans2 = "What do you mean? African or European swallow?";

		vector<string> ops = {ans1, ans2};
		
		int menu1;
		do
		{
		menu1 = menu(ops, 2);

		if (menu1==1)
		{	//wrong answer
			cout << "Old Man: Wrong...try again" << endl;
			cout << "---You gave up one point to try again..." << endl;
			prot.losePoint();
		}
		else if (menu1==2)
		{
			//"right" answer
			cout << "\nOld Man: What? I don't know that!!" << endl;
			cout << "---The ghost suddenly flies and disappears"
				<< ", allowing you to go on with your quest..."
				<< endl;
			prot.gainPoint();
			prot.gainPoint();
			cout << "---You gained two points..." << endl;
			break;
		}
		} while (menu1!=2);
	
}
