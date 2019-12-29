/**************************************************************************************************
 * * Program name: Gameplay.cpp
 * * Author: Julian Torres
 * * Date: 06 December 2019
 * * Description: This is the implementation file for the Gameplay class. This class contains all
 * *		  functions essential to gameplay, including a menu. It links Space objects
 * *		  together to build the map.
 * ************************************************************************************************/

#include "Gameplay.hpp"
#include "Space.hpp"
#include "Ocean.hpp"
#include "Beach.hpp"
#include "Forest.hpp"
#include "Volcano.hpp"

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 * * Gameplay::Gameplay()
 * * Description: This constructor is used to connect the spaces and assign the player to a
 * *		  starting position.
 * ************************************************************************************************/
Gameplay::Gameplay(){
	gameStatus = true;

	// Allocate memory for Space objects
	ocean = new Ocean("Ocean");
	northwestBeach = new Beach("Northwest Beach");
	northeastBeach = new Beach("Northeast Beach");
	bambooForest = new Forest("Bamboo Forest");
	denseForest = new Forest("Dense Forest");
	lavaField = new Volcano("Lava Field");
	activeVolcano = new Volcano("Active Volcano");
	southwestBeach = new Beach("Southwest Beach");
	southeastBeach = new Beach("Southeast Beach");

	// Link the Space objects together
	northwestBeach->addSpace(ocean, northeastBeach, bambooForest, ocean);
	northeastBeach->addSpace(ocean, ocean, denseForest, northwestBeach);
	bambooForest->addSpace(northwestBeach, denseForest, lavaField, ocean);
	denseForest->addSpace(northeastBeach, ocean, activeVolcano, bambooForest);
	lavaField->addSpace(bambooForest, activeVolcano, southwestBeach, ocean);
	activeVolcano->addSpace(denseForest, ocean, southeastBeach, lavaField);
	southwestBeach->addSpace(lavaField, southeastBeach, ocean, ocean);
	southeastBeach->addSpace(activeVolcano, ocean, ocean, southwestBeach);

	currentSpace = northwestBeach; // Set the starting position

	// Add items to the necessary spaces
	northwestBeach->addSpaceItems("Driftwood");
	northwestBeach->addSpaceItems("Coconuts");
	northwestBeach->addSpaceItems("Wilson, the Volleyball");

	northeastBeach->addSpaceItems("Sturdy Wood");
	northeastBeach->addSpaceItems("Coconuts");
	northeastBeach->addSpaceItems("Nails");

	bambooForest->addSpaceItems("Bamboo Logs");
	bambooForest->addSpaceItems("Bananas");
	bambooForest->addSpaceItems("Palm Leaves");

	denseForest->addSpaceItems("Teak Logs");
	denseForest->addSpaceItems("Guavas");
	denseForest->addSpaceItems("Hemp Plants");

	southwestBeach->addSpaceItems("Drift Wood");
	southwestBeach->addSpaceItems("Rotten Coconuts");
	southwestBeach->addSpaceItems("A Hammer");

	southeastBeach->addSpaceItems("Drift Wood");
	southeastBeach->addSpaceItems("Coconuts");
	southeastBeach->addSpaceItems("Twine");

	backpack.push_back("Coconuts"); // Add one food item to the backpack

	// Assign values to these essential gameplay variables to control the difficulty
	energy = 6;
	maxEnergy = 8;
	capacity = 7;
	eruption = 15;
	daysElapsed = 0; // Keep track of the number of rounds

}

/**************************************************************************************************
 * * void Gameplay::gameDescription()
 * * Description: This function is prints out a description of the game details.
 * ************************************************************************************************/
void Gameplay::gameDescription(){
	std::string prompt;

	std::cout << std::endl;
	std::cout << std::endl << "================== Game Description ==================";
	std::cout << std::endl;
	std::cout << std::endl << "It was Christmas day, and you were on board of a"
		  << std::endl << "United States Postal Service flight. You had to be on"
		  << std::endl << "this plane for some reason. You actually just proposed"
		  << std::endl << "to your partner moments before taking off. Two hours"
		  << std::endl << "into the flight, while you were over the Pacific"
		  << std::endl << "Ocean, you realize that you should have went to"
		  << std::endl << "Jared's. As you are in this train of thought, the"
		  << std::endl << "plane crashes. You barely escape. Out in the not too"
		  << std::endl << "far, but not too close, but manageable distance, you"
		  << std::endl << "see an island with an active volcano on it. You go to"
		  << std::endl << "this island. You must now escape the island that you"
		  << std::endl << "just got to. Gather supplies to build a boat. You will"
		  << std::endl << "need a boat frame, mast, and sail. You must locate the"
		  << std::endl << "raw materials needed to build the boat, but be sure to"
		  << std::endl << "also keep your energy up by consuming plant-based"
		  << std::endl << "foods that are good for the mind, body, and holy"
		  << std::endl << "spirit. Each day, you will need to expend one energy"
		  << std::endl << "point. If you choose to attempt to build an item with"
		  << std::endl << "the contents of your pack, you will expend an"
		  << std::endl << "additional energy point. Construct the boat, channel"
		  << std::endl << "the most authentic version of yourself, and have"
		  << std::endl << "yourself a merry little Christmas while you are at it."
		  << std::endl;

	std::cout << std::endl << "Enter anything to continue: ";
	getline(std::cin, prompt);
}

/**************************************************************************************************
 * * bool Gameplay::checkOcean()
 * * Description: This function is used to check the contents of the backpack for a boat. If the
 * *		  player does not have a boat, this function prohibits the player from entering the
 * *		  Ocean space.
 * ************************************************************************************************/
bool Gameplay::checkOcean(){
	if(std::find(backpack.begin(), backpack.end(), "Boat") == backpack.end()){
		std::cout << std::endl << "You should not be here. You do not have"
			  << std::endl << "a boat to traverse these waters." << std::endl;

		currentSpace = previousSpace; // Return the player to the previous space

		return false;
	}
	
	else{
		gameStatus = false;

		return true;
	}
}

/**************************************************************************************************
 * * void Gameplay::replenishEnergy(int amount)
 * * Description: This function is used to replenish the energy of the player by a passed amount of
 * *		  points.
 * ************************************************************************************************/
void Gameplay::replenishEnergy(int amount){
	energy += amount;
	
	std::cout << std::endl;

	// Ensure the energy does not exceed to maximum amount
	if(energy >= maxEnergy){
		energy = maxEnergy;

		std::cout << std::endl << "You have reached the maximum energy of "
			  << maxEnergy << " points." << std::endl << "You feel invigorated!";
	}

	else{
		std::cout << std::endl << "You increased your energy points by " << amount << "."
			  << std::endl << "You now have " << energy << " energy points!";
	}
}

/**************************************************************************************************
 * * void Gameplay::consumeFood(std::string itemName)
 * * Description: This function is used to consume an item in the backpack at the passed index.
 * ************************************************************************************************/
void Gameplay::consumeFood(std::string itemName){
	if(itemName == "Coconuts"){
		std::cout << std::endl << "You drank the juice and ate the meat of those"
			  << std::endl << "coconuts! Delicious and healthful!";

		replenishEnergy(3);
	}
	
	else if(itemName == "Bananas"){
		std::cout << std::endl << "Those apple bananas were terrific!";

		replenishEnergy(2);
	}

	else if(itemName == "Guavas"){
		std::cout << std::endl << "Those guavas were a real treat!";

		replenishEnergy(2);
	}
}

/**************************************************************************************************
 * * void Gameplay::checkFood()
 * * Description: This function checks if the player has any food in the backpack. If there is an
 * *		  item that can be consumed, the player is prompted to eat.
 * ************************************************************************************************/
void Gameplay::checkFood(){
	std::string prompt;

	std::cout << std::endl;

	// The conditional is necessary so the player does not waste food
	if(energy < (maxEnergy - 2)){
		// These variables will hold the index of the food items. If such an item exists,
		// the food item that yields the least amount of energy will be consumed first.
		int coconuts = -1,
		    bananas = -1,
		    guavas = -1;

		// Scan the vector
		for(int index = 0; index < backpack.size(); index++){
			if(backpack.at(index) == "Coconuts"){ coconuts = index; }
			else if(backpack.at(index) == "Bananas"){ bananas = index; }
			else if(backpack.at(index) == "Guavas"){ guavas = index; }
		}

		// Eat the lowest yield item first to prevent overconsumption
		if(guavas != -1){
			consumeFood("Guavas");
			backpack.erase(backpack.begin() + guavas);
		}
		else if(bananas != -1){
			consumeFood("Bananas");
			backpack.erase(backpack.begin() + bananas);
		}
		else if(coconuts != -1){
			consumeFood("Coconuts");
			backpack.erase(backpack.begin() + coconuts);
		}

		// No food item was located in the vector
		else{ std::cout << std::endl << "I should start gathering food..."; }
	}

	// The player has a high energy level
	else{ std::cout << std::endl << "I am not too hungry at the moment."; }

	std::cout << std::endl;
	std::cout << std::endl << "Enter anything to continue: ";
	getline(std::cin, prompt);
}

/**************************************************************************************************
 * * void Gameplay::checkStatus()
 * * Description: This function is used to determine the status of the game. If daysElapsed exceeds
 * *		  the limit, the game is over.
 * ************************************************************************************************/
void Gameplay::checkStatus(){
	// The player exceeded the maximum amount of time
	if(daysElapsed >= eruption){
		std::cout << std::endl;
		std::cout << std::endl << "The Volcano has erupted!";
		std::cout << std::endl << "Oh no... the lava is coming right at you!";
		std::cout << std::endl;
		std::cout << std::endl << "Game over.";
		std::cout << std::endl;
		std::cout << std::endl;

		gameStatus = false;
	}

	// The player did not consume enough food
	else if(energy <= 0){
		std::cout << std::endl;
		std::cout << std::endl << "You have become too weak to continue!";
		std::cout << std::endl << "You have perished, at least on a beautiful island.";
		std::cout << std::endl;
		std::cout << std::endl << "Game over.";
		std::cout << std::endl;
		std::cout << std::endl;

		gameStatus = false;
	}

	// The player has low energy points. Warn the user.
	else if(energy <= 2){
		std::cout << std::endl;
		std::cout << std::endl << "Without replenishment, you are becoming weak.";
		std::cout << std::endl << "Find some sustenance before it is too late.";
		std::cout << std::endl;
		
		if(energy == 1){ std::cout << std::endl << "You have 1 energy point remaining."; }

		else{ std::cout << std::endl << "You have 2 energy points remaining."; }

		std::cout << std::endl;
	}
}

/**************************************************************************************************
 * * void Gameplay::checkBackpack()
 * * Description: This function checks the backpack capacity before moving to a new space.
 * ************************************************************************************************/
void Gameplay::checkBackpack(){
	if(backpack.size() == capacity){
		std::string itemName;

		int index;

		// Display the contents of the backpack
		std::cout << std::endl;
		std::cout << std::endl << "Your backpack is full! You must use or remove an item"
			  << std::endl << "before continuing.";
		std::cout << std::endl;
		std::cout << std::endl << "====================== Backpack ======================";
		std::cout << std::endl;
		
		for(index = 0; index < capacity; index++){
			std::cout << std::endl << (index + 1) << ". " << backpack.at(index);
		}

		std::cout << std::endl;
		std::cout << std::endl << "Which item do you wish to remove: ";
		getline(std::cin, itemName);

		// Validate input. At this point, the user will have a total of seven items in the
		// backpack.
		while(itemName != "1" && itemName != "2" && itemName != "3"
				      && itemName != "4" && itemName != "5"
				      && itemName != "6" && itemName != "7"){
			std::cout << std::endl << "Please enter a valid menu option: ";
			getline(std::cin, itemName);
		}

		index = std::stoi(itemName); // Convert the choice to an integer
		index--; // Account for the index error

		itemName = backpack.at(index);

		// Check if the item is a food item. If it is, consume it before discarding it from
		// the backpack.
		if(itemName == "Coconuts" || itemName == "Bananas" || itemName == "Guavas"){
			consumeFood(itemName);
			std::cout << std::endl;
		}
		
		// The item was not a food item
		else{ std::cout << std::endl << "You removed " << itemName << " from your pack."; }

		backpack.erase(backpack.begin() + index); // Remove the item from the pack
	}
}

/**************************************************************************************************
 * * void Gameplay::displayBackpack()
 * * Description: This function displays the contents of the backpack, and it allows the user to
 * *		  build and use items if possible.
 * ************************************************************************************************/
void Gameplay::displayBackpack(){
	std::string option,
		    prompt;

	std::cout << std::endl;

	if(backpack.size() == 0){
		std::cout << std::endl << "Your backpack is empty. You"
			  << std::endl << "should start gathering items...";
	}
	
	// The backpack has at least one item. Display the contents.
	else{
		std::cout << std::endl << "====================== Backpack ======================";
		std::cout << std::endl;
		
		std::cout << std::endl << "Backpack contents: ";

		for(int index = 0; index < backpack.size(); index++){
			if(index == 0){ std::cout << backpack.at(index); }

			else{
				std::cout << std::endl << std::string(19, ' ')
					  << backpack.at(index);
			}
		}
	}

	// Prompt the use to attempt to build an item
	if(energy > 2 && backpack.size() >= 1){
		std::cout << std::endl;
		std::cout << std::endl << "Would you like to spend an energy point";
		std::cout << std::endl << "on an attempt to build an item?";
		std::cout << std::endl;
		std::cout << std::endl << "1. Yes";
		std::cout << std::endl << "2. No";
		std::cout << std::endl;
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, option);

		// Validate input
		while(option != "1" && option != "2"){
			std::cout << std::endl << "Please enter a valid menu option: ";
			getline(std::cin, option);
		}

		// The player chose to attempt to build an item
		if(option == "1"){ buildItems(); }

		// The player does not want to build an item at this time. Warn the user that time
		// is of the essence.
		else{
			std::cout << std::endl << "You need to get off of this island..."
				  << std::endl << "It is only a matter of time before the"
				  << std::endl << "volcano erupts.";
		}
	}

	// The user does not have enough energy to attempt to build an item. Warn the user that the
	// energy level is low.
	else if(energy == 2 && backpack.size() >= 1){
		std::cout << std::endl;
		std::cout << std::endl << "You are feeling a bit weak today...";
	}

	// The backpack is empty
	else{
		std::cout << std::endl;
		std::cout << std::endl << "I am not feeling too well...";
	}

	std::cout << std::endl;
	std::cout << std::endl << "Enter anything to continue: ";
	getline(std::cin, prompt);
}

/**************************************************************************************************
 * * void Gameplay::buildItems()
 * * Description: This function checks if the backpack contains items that can be built. If an item
 * *		  can be built, the program prompts the user accordingly.
 * ************************************************************************************************/
void Gameplay::buildItems(){
	srand(time(0));

	// The user has a three out of four chance in making a successful build if the necessary
	// materials are in the backpack.
	if(((rand() % 4) + 1) >= 2){
		std::vector<std::string> buildChoices;

		bool buildStatus = false;

		// Hold the index of necessary build tools
		int hammer = -1,
		    nails = -1,
		    twine = -1,
		    boatFrame = -1,
		    mast = -1,
		    sail = -1,
		    hempPlants = -1,
		    palmLeaves = -1,
		    bambooLogs = -1,
		    sturdyWood = -1,
		    teakLogs = -1;

		// Scan the backpack for items, and record the index
		for(int index = 0; index < backpack.size(); index++){
			if(backpack.at(index) == "A Hammer"){ hammer = index; }
			else if(backpack.at(index) == "Nails"){ nails = index; }
			else if(backpack.at(index) == "Twine"){ twine = index; }
			else if(backpack.at(index) == "Boat Frame"){ boatFrame = index; }
			else if(backpack.at(index) == "Mast"){ mast = index; }
			else if(backpack.at(index) == "Sail"){ sail = index; }
			else if(backpack.at(index) == "Hemp Plants"){ hempPlants = index; }
			else if(backpack.at(index) == "Palm Leaves"){ palmLeaves = index; }
			else if(backpack.at(index) == "Bamboo Logs"){ bambooLogs = index; }
			else if(backpack.at(index) == "Sturdy Wood"){ sturdyWood = index; }
			else if(backpack.at(index) == "Teak Logs"){ teakLogs = index; }
		}

		// Check if the player has necessary materials to build an item
		if(hempPlants != -1){
			std::cout << std::endl << "You created Twine from the Hemp Plants!";
			backpack.at(hempPlants) = "Twine";
			buildStatus = true;
		}

		if(palmLeaves != -1){
			std::cout << std::endl << "You created a Sail from the Palm Leaves!";
			backpack.at(palmLeaves) = "Sail";
			buildStatus = true;
		}

		if(bambooLogs != -1){
			std::cout << std::endl << "You created a Mast from the Bamboo Logs!";
			backpack.at(bambooLogs) = "Mast";
			buildStatus = true;
		}

		if(sturdyWood != -1 && hammer != -1 && nails != -1){
			std::cout << std::endl << "You created a Boat Frame from the"
				  << std::endl << "Sturdy Wood, Hammer, and Nails!";
			backpack.at(sturdyWood) = "Boat Frame";
			buildStatus = true;
		}

		if(teakLogs != -1 && hammer != -1 && nails != -1){
			std::cout << std::endl << "You created a Boat Frame from the"
				  << std::endl << "Teak Logs, Hammer, and Nails!";

			backpack.at(teakLogs) = "Boat Frame";
			buildStatus = true;
		}

		// The player has the necessary items to build a boat
		if(twine != -1 && boatFrame != -1 && mast != -1 && sail != -1
			       && hammer != -1 && nails != -1){
			std::cout << std::endl << "You created a Boat from the Boat Frame, Mast,"
				  << std::endl << "Sail, Hammer, and Nails!";

			backpack.at(boatFrame) = "Boat";

			if(mast < sail){
				backpack.erase(backpack.begin() + sail);
				backpack.erase(backpack.begin() + mast);
			}
			else{
				backpack.erase(backpack.begin() + mast);
				backpack.erase(backpack.begin() + sail);
			}

			buildStatus = true;
		}

		// The player did not have the necessary materials to build any items
		if(!buildStatus){
			std::cout << std::endl << "You tried to come up with something, but you"
				  << std::endl << "did not have enough materials to build with...";
		}
	}

	// There is a one out of four chance the player will fall asleep while building
	else{
		std::cout << std::endl << "You were so tired that you fell asleep"
			  << std::endl << "while working!";
	}

	energy--; // Decrement the energy level by one point regardless of a successful build
}

/**************************************************************************************************
 * * void Gameplay::movePlayer()
 * * Description: This function is used to move the player object to a new space.
 * ************************************************************************************************/
void Gameplay::movePlayer(){
	std::string menuOption,
		    prompt;

	bool oceanCheck = false;

	// Store the current location here. The player will be sent back to the former location if
	// attempting to access the ocean without a boat.
	previousSpace = currentSpace;

	daysElapsed++; // Increment the round tracking variable

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl << "=================== Start of Day " << daysElapsed
		 	       << " ===================";

	while(oceanCheck == false){
		// Prompt the user to choose a space to travel to
		std::cout << std::endl;
		std::cout << std::endl << "Where would you like to go?";
		std::cout << std::endl;
		std::cout << std::endl << "1. North: " << currentSpace->getNorthSpaceName();
		std::cout << std::endl << "2. East: " << currentSpace->getEastSpaceName();
		std::cout << std::endl << "3. South: " << currentSpace->getSouthSpaceName();
		std::cout << std::endl << "4. West: " << currentSpace->getWestSpaceName();
		std::cout << std::endl << "5. Nearby location: "
	  	          << currentSpace->getSpaceName();
		std::cout << std::endl;
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, menuOption);

		// Validate input
		while(menuOption != "1" && menuOption != "2" && menuOption != "3"
					&& menuOption != "4" && menuOption != "5"){
			std::cout << std::endl << "Please enter a valid menu option: ";
			getline(std::cin, menuOption);
		}

		std::cout << std::endl;

		// Assign the new location to the player
		if(menuOption == "1"){ currentSpace = currentSpace->getNorthSpace(); }
		else if(menuOption == "2"){ currentSpace = currentSpace->getEastSpace(); }
		else if(menuOption == "3"){ currentSpace = currentSpace->getSouthSpace(); }
		else if(menuOption == "4"){ currentSpace = currentSpace->getWestSpace(); }
		else{ currentSpace = previousSpace; }

		// Check if the player is trying to access the ocean, and perform necessary
		// protocols.
		if(currentSpace->getSpaceName() != "Ocean"){ oceanCheck = true; }
		else{ oceanCheck = checkOcean(); }
	}

	currentSpace->spaceInteraction(backpack, capacity); // Interact with the new space

	std::cout << std::endl;
	std::cout << std::endl << "Enter anything to continue: ";
	getline(std::cin, prompt);

	if(gameStatus){ checkFood(); } // Attempt to consume food 
}

/**************************************************************************************************
 * * void Gameplay::endOfDay()
 * * Description: This function is used to display the current day, amount of energy points, and
 * *		  current location.
 * ************************************************************************************************/
void Gameplay::endOfDay(){
	energy--; // Decrement the energy level by one point

	checkStatus(); // Check if the user has run out of energy or reached the time limit

	// The player has not lost the game
	if(gameStatus){
		std::string prompt;

		// Print out pertinent game details
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl << "==================== End of Day " << daysElapsed
				       << " ====================";
		std::cout << std::endl;
		std::cout << std::endl << "Current location: " << currentSpace->getSpaceName();
		std::cout << std::endl << "Energy points: " << energy;
		std::cout << std::endl << "Backpack contents: ";

		if(backpack.size() == 0){ std::cout << "None"; }

		else{
			for(int index = 0; index < backpack.size(); index++){
				if(index == 0){ std::cout << backpack.at(index); }

				else{
					std::cout << std::endl << std::string(19, ' ')
						  << backpack.at(index);
				}
			}
		}

		std::cout << std::endl;
		std::cout << std::endl << "Enter anything to continue: ";
		getline(std::cin, prompt);

		checkFood(); // Consume food if possible
	}
}

/**************************************************************************************************
 * * Gameplay::~Gameplay()
 * * Description: This destructor frees all dynamically allocated memory.
 * ************************************************************************************************/
Gameplay::~Gameplay(){
	delete ocean;
	delete northwestBeach;
	delete northeastBeach;
	delete bambooForest;
	delete denseForest;
	delete lavaField;
	delete activeVolcano;
	delete southwestBeach;
	delete southeastBeach;

	ocean = nullptr;
	northwestBeach = nullptr;
	northeastBeach = nullptr;
	bambooForest = nullptr;
	denseForest = nullptr;
	lavaField = nullptr;
	activeVolcano = nullptr;
	southwestBeach = nullptr;
	southeastBeach = nullptr;
}

