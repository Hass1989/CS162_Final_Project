/******************************************************************************
** Program name: Final Project - Map.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declarations of the linked data
** structure, Map.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Space.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map
{
	protected:
		Space* start;
		vector<Space*> list;
		int size;
	public:
		Map();
		void position(int k, int t, int b, int l, int r);
		int getSize();
		void print(int pos);
		Space* getSpace(int k);
		void addSpace(Space* room);
};

#endif
