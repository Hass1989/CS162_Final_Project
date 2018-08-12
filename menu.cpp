/******************************************************************************
** Program name: Lab4 - menu.cpp
** Author: Hassan Alarafat
** Date: April 30, 2018
** Description: This file contains the definition of the menu function. It takes
** in an array of options representing the items on the list and the number of
** said items. It displays the items and asks the user to choose, then calls
** on the validation functions to make sure the choice is valid.
*******************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
#include <vector>
#include "validation.hpp"

int menu(std::vector<string> options, int num)
{
	int decision;	
	
	cout << "\n";	

	for (int i=1; i <= num; i++)
	{
		cout << i << ". " << options[i-1] << endl;
	}
	
	//calls function to validate choices
	decision = validChoice(validInt(true), num);

	return decision;
}
