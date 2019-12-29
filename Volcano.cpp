/**************************************************************************************************
 * * Program name: Volcano.cpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the implementation file of the Volcano class. This is a derived class, in
 * *		  which it inherits from the Space class. Objects of this class pose a risk to the
 * *		  player, where items may be removed from the backpack.
 * ************************************************************************************************/

#include "Volcano.hpp"

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 * * void Volcano::spaceDescription()
 * * Description: This function provides a message about the Space.
 * ************************************************************************************************/
void Volcano::spaceDescription(){
	std::cout << std::endl << "You made your way to the " << spaceName << ".";
	std::cout << std::endl << "I do not think this is a safe place to be...";
	std::cout << std::endl;
}

/**************************************************************************************************
 * * void Volcano::spaceInteraction(std::vector<std::string> backpack, capacity)
 * * Description: This function accesses the player's backpack, in which the player has a one out
 * *		  of three chance of losing the last item placed into the backpack.
 * ************************************************************************************************/
void Volcano::spaceInteraction(std::vector<std::string>& backpack, int capacity){
	spaceDescription();

	int item;

	std::cout << std::endl << "Lava just shot out of the volcano!";
	std::cout << std::endl << "You need to get out of here, now!";
	std::cout << std::endl;
	std::cout << std::endl << "1. Run away from lava";
	std::cout << std::endl << "2. Take a selfie";
	std::cout << std::endl;
	std::cout << std::endl << "Please enter a valid menu option: ";
	getline(std::cin, menuOption);

	while(menuOption != "1" && menuOption != "2"){
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, menuOption);
	}

	// If the player chooses to run, there is a one out of three chance of losing an item
	if(menuOption == "1"){
		srand(time(0));

		if(((rand() % 3) + 1) == 1 && backpack.size() >= 1){
			std::cout << std::endl << "Oh no! I think something fell out of my pack!";
			backpack.pop_back(); // Remove the last item
		}

		else{ std::cout << std::endl << "That was a close call!"; }
	}
	
	// If the player chooses to take a selfie, the last item of the backpack will be removed
	else{
		std::cout << std::endl << "I don't have my phone to take a selfie!"
			  << std::endl << "What was I thinking!";
		
		if(backpack.size() >= 1){
			std::cout << std::endl;
			std::cout << std::endl << "Oh no! Something fell out of my pack!";
			backpack.pop_back(); // Remove the last item
		}
	}
}

