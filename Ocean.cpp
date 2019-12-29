/**************************************************************************************************
 * * Program name: Ocean.cpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the implementation file of the Ocean class. This is a derived class, in
 * *		  which it inherits from the Space class. This is the last space a player will
 * *		  access. The player is unable to access this space until a boat has been
 * *		  constructed.
 * ************************************************************************************************/

#include "Ocean.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 * * void Ocean::spaceDescription()
 * * Description: This function provides a message about the Space.
 * ************************************************************************************************/
void Ocean::spaceDescription(){
	std::cout << std::endl << "You have reached the Ocean! The current is strong,";
	std::cout << std::endl << "the winds are high, and the water is murky.";
	std::cout << std::endl;
}

/**************************************************************************************************
 * * void Ocean::spaceInteraction(std::vector<std::string> backpack)
 * * Description: This function is only accessed by properly constructing a boat, in which the
 * *		  player will have won the game.
 * ************************************************************************************************/
void Ocean::spaceInteraction(std::vector<std::string>& backpack, int capacity){
	spaceDescription();

	std::cout << std::endl << "You board your boat and take off in search of";
	std::cout << std::endl << "rescue! You made it off the island. Now, the";
	std::cout << std::endl << "real challenge begins...";
}

