/******************************************************************************
** Program name: Final Project - Game.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Game.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>
#include <vector>
using std::vector;
#include "Space.hpp"
#include "Protagonist.hpp"
#include "Map.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	protected:
		int position;
		bool bossDead;
		Map map;
		vector<bool> items;
	public:
		Game();
		void arrive(int pos);
		void checkItems();
		void addItem(int key);
		void useItems(Protagonist &prot);
};

#endif
