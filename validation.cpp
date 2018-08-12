/******************************************************************************
** Program name: Lab5 - validation.cpp
** Author: Hassan Alarafat
** Date: May 4, 2018
** Description: This file contains two input validation functions that are
** used to make sure input values are reasonable and do not crash the program.
*******************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cctype>	//for isdigit, isspace
#include <string>
using std::string;
#include <cstdlib>

/****************************************************************************
** Description: This function makes sure the input is an integer. It repeats
** until user enters the desired results. Characters, spaces, and floating
** points are rejected as the needed input is an integer only.
****************************************************************************/
int validInt(bool positive)
{
	string input;
	bool valid = true, space;
	size_t dot;
	int num, length;
	do	
	{
		space=false;
		
		//reads the user's input
		std::getline(cin, input);
		dot = input.find(".");
		
		//if a dot has been found, then the input could be a double
		//or float, the program asked for an integer only
		if (dot!= std::string::npos)
			valid = false;
		else
			valid = true;
	
		length = input.length();
		//iterates over and tests each character in the input string
		for (int i=0; i < length; i++)
		{
			//checks to see if there is a space in the string
			if(isspace(input[i]))
			{
				space = true;
				valid = false;
			}
			else if(input[i]=='-'|| input[i]=='+')//checks for sign
			{
				i++;
			}
			//makes sure all characters in the string are digits
			else if(isdigit(input[i]) && valid)
				valid = true;
			else
				valid = false;
		}
		
		if (positive)
		{
			if (atoi(input.c_str())<=0)
				valid=false;
		}
		
		//makes sure the input is a valid integer, has no space
		if (space==true&&valid==false)
		{
			cout << "Error! No space, please. ";
		}
		else if (valid==false)
		{
			cout << "Error! Input a positive integer: ";
		}	
		
	} while(valid==false); //loops through multiple tests
	
	//if the input passes all the tests, then it gets converted to int
	if (valid==true)
		num = atoi(input.c_str());

	return num;
}

/****************************************************************************
** Description: This function validates the choice as part of the actual list
** of choices. It is used with menus which needs the user to choose an item.
** The choices have to be represented with an array of integers with a 
** number of elements equal to that of the number of items on the menu.
****************************************************************************/
int validChoice(int choice, int num)
{
	int *arrayChoices = new int[num];
	
		
	for (int i=0; i < num; i++)
	{
		arrayChoices[i] = i+1;
	}

	bool choiceFound=true;
	
	for (int i=0; i < num; i++)
	{
		//number input by user is indeed one of the choices offered
		if (choice==arrayChoices[i])
		{
			choiceFound = true;
			break;
		}
		else
		{
			choiceFound = false;
		}
	}
	
	delete [] arrayChoices;
	
	do
	{
		if (!choiceFound)
		{
			cout << "Please input valid choice: ";
			
			//If choice isn't found on list, asks for input again
			return validChoice(validInt(true), num);
		}
		else
			return choice;
		} while (!choiceFound);

}
