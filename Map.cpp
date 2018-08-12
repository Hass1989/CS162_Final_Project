/******************************************************************************
** Program name: Final Project - Map.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declarations of the linked data
** structure, Map.
*******************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Space.hpp"
#include "Map.hpp"

//Space* start;
//Space* end;
	
Map::Map()
{
	start = NULL;
	size = 0;
}

int Map::getSize()
{
	return list.size();
}

Space* Map::getSpace(int k)
{
	Space* temp=NULL;

	if (k!=0)
	{
		for (unsigned i=0; i < list.size(); i++)
		{
			if (list[i]->getKey()==k)
			{
				temp=list[i];
				break;
			}
		}
	}

	return temp;
}

void Map::addSpace(Space* room)
{
	Space* newSpace = new Space();

	if (start==NULL)
	{
		start = newSpace;
		list.push_back(room);
		size = list.size();
	}
	else
	{	
		list.push_back(room);
		size = list.size();
	}

	delete newSpace;
}

void Map::position(int k, int t, int b, int l, int r)
{
	Space* temp = getSpace(k);
	temp->linkTop(getSpace(t));
	temp->linkBot(getSpace(b));
	temp->linkLeft(getSpace(l));
	temp->linkRight(getSpace(r));

}

void Map::print(int position)
{
	int key=0;
	string player = "******";

	cout << "|\t" << "-" << "\t|" << "|\t" << list[10]->getType()
		<< "\t|" << "|\t" << "-" << "\t|" << endl;
	for (int i=1; i <= 3; i++)
	{
		
		for (int j=1; j <= 3; j++)
		{
			
			if ((position-1)!=(key))
			{
			cout << "|\t" << list[key]->getType() << "\t|";
			key++;
			}
			else
			{
			cout << "|\t" << player << "\t|";
			key++;
			}

		}
		cout << endl;
	}	
	
	cout << "|\t" << "-" << "\t|" << "|\t" << list[9]->getName()
		<< "|" << "|\t" << "-" << "\t|" << endl;


}
