/******************************************************************************
** Program name: Proj4 - main.cpp
** Author: Hassan Alarafat
** Date: May 28, 2018
** Description: This is the main function of the project. It only contains
** a declaration of an object of the class Game. 
*******************************************************************************/
#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "menu.hpp"
#include "validation.hpp"
#include "Game.hpp"

int main ()
{
	string op1 = "Play";
	string op2 = "Exit";

	vector<string> ops = {op1, op2};

	int menu1 = menu(ops, 2);

	while (menu1!=2)
	{
		Game game;
		
		op1 = "Play again";
		ops = {op1, op2};
		menu1 = menu(ops, 2);
	}

	std::cout << "===Goodbye===" << std::endl;
}
