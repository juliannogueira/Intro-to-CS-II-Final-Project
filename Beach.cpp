/**************************************************************************************************
 * * Program name: Beach.cpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the implementation file of the Beach class. This is a derived class, in
 * *		  which it inherits from the Space class. There a total of four beaches in the
 * *		  Island Escape game.
 * ************************************************************************************************/

#include "Beach.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 * * void Beach::spaceDescription()
 * * Description: This function provides a message about the Space.
 * ************************************************************************************************/
void Beach::spaceDescription(){
	std::cout << std::endl << "You have arrived at the " << spaceName << ".";
	std::cout << std::endl << "These beaches all look the same...";
	std::cout << std::endl;
}

/**************************************************************************************************
 * * void Beach::spaceInteraction(std::vector<std::string> backpack, capacity)
 * * Description: This function accesses the player's backpack, in which an item will be pushed
 * *		  into the vector.
 * ************************************************************************************************/
void Beach::spaceInteraction(std::vector<std::string>& backpack, int capacity){
	spaceDescription(); // Provide the space description

	int item;

	std::cout << std::endl << "We have to figure this out... Time is limited";
	std::cout << std::endl << "and we need supplies to build a boat.";
	std::cout << std::endl;
	std::cout << std::endl << "1. Collect drift wood";
	std::cout << std::endl << "2. Check the trees for coconuts";
	std::cout << std::endl << "3. Search in the sand for supplies";
	std::cout << std::endl;
	std::cout << std::endl << "Please enter a valid menu option: ";
	getline(std::cin, menuOption);

	// Validate input
	while(menuOption != "1" && menuOption != "2" && menuOption != "3"){
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, menuOption);
	}

	item = std::stoi(menuOption);

	std::cout << std::endl << "You found " << spaceItems.at(item - 1) << "!";

	// Add the item to the vector
	backpack.push_back(spaceItems.at(item - 1));
}

