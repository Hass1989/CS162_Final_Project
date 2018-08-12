/******************************************************************************
** Program name: Final Project - Store.hpp
** Author: Hassan Alarafat
** Date: June 10, 2018
** Description: This file contains the declaration of the class Store.
*******************************************************************************/
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdlib>
#include "Character.hpp"
#include "Protagonist.hpp"

#ifndef STORE_HPP
#define STORE_HPP

class Store : public Space
{
	protected:
		
	public:
		Store();
		Store(int k, string n);
		void interact(Protagonist &prot);
};

#endif
