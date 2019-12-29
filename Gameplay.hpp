/**************************************************************************************************
 * * Program name: Gameplay.hpp
 * * Author: Julian Torres
 * * Date: 06 December 2019
 * * Description: This is the header file for the Gameplay class. This class is used to run the
 * *		  Island Escape game. The Space class, and its derived classes, are used to build
 * *		  the map, in which the constructor links Space objects together. The class
 * *		  contains all essential gameplay functions.
 * ************************************************************************************************/

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Space.hpp"

#include <vector>
#include <string>

class Gameplay{
	protected:
		// These pointers will be used to build the map
		Space* ocean;
         	Space* northwestBeach;
		Space* northeastBeach;
		Space* bambooForest;
		Space* denseForest;
		Space* lavaField;
		Space* activeVolcano;
		Space* southwestBeach;
		Space* southeastBeach;

		Space* currentSpace; // This holds the player's current location
		Space* previousSpace;

		std::vector<std::string> backpack; // Store collected items in this vector

		// These variables determine the status of gameplay
		int energy,
		    maxEnergy,
		    capacity,
		    eruption,
		    daysElapsed;

		bool gameStatus; // The program terminates if this bool equals false

	public:
		Gameplay(); // Build map and allocate memory
		~Gameplay(); // Deallocate memory

		void gameDescription();

		// The program terminates if gameStatus equals false
		bool getGameStatus(){ return gameStatus; }

		bool checkOcean(); // Check if the player is able to go to the ocean
		void replenishEnergy(int amount);
		void consumeFood(std::string itemName);
		void checkFood(); // Check if the player has food to consume
		void checkStatus();
		void checkBackpack();
		void displayBackpack();
		void endOfDay(); // Display pertinent information to the player
		void buildItems(); // Prompt the user to attempt to build an item
		void movePlayer(); // Prompt the user to go to a new location
};

#endif

