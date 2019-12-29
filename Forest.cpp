/**************************************************************************************************
 * * Program name: Forest.cpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the implementation file of the Forest class. This is a derived class, in
 * *		  which it inherits from the Space class. There are two forests in the Island
 * *		  Escape game. This space contains essential items to build the boat.
 * ************************************************************************************************/

#include "Forest.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 * * void Forest::spaceDescription()
 * * Description: This function provides a message about the Space.
 * ************************************************************************************************/
void Forest::spaceDescription(){
	std::cout << std::endl << "You have arrived at the " << spaceName << ".";
	std::cout << std::endl << "There has to be something useful here...";
	std::cout << std::endl;
}

/**************************************************************************************************
 * * void Forest::spaceInteraction(std::vector<std::string> backpack, capacity)
 * * Description: This function accesses the player's backpack, in which an item will be added to
 * *		  the vector.
 * ************************************************************************************************/
void Forest::spaceInteraction(std::vector<std::string>& backpack, int capacity){
	spaceDescription();

	int item;

	std::cout << std::endl << "We have to figure this out... Time is limited";
	std::cout << std::endl << "and we need supplies to build a boat.";
	std::cout << std::endl;
	std::cout << std::endl << "1. Collect wood";
	std::cout << std::endl << "2. Check the forest for something edible";
	std::cout << std::endl << "3. Look for weaving material";
	std::cout << std::endl;
	std::cout << std::endl << "Please enter a valid menu option: ";
	getline(std::cin, menuOption);

	while(menuOption != "1" && menuOption != "2" && menuOption != "3"){
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, menuOption);
	}

	item = std::stoi(menuOption);

	std::cout << std::endl << "You found " << spaceItems.at(item - 1) << "!";

	// Add the item to the backpack
	backpack.push_back(spaceItems.at(item - 1));
}

