/**************************************************************************************************
 * * Program name: Forest.hpp
 * * Author: Julian Torres
 * * Date: 08 December 2019
 * * Description: This is the header file of the Forest class. This is a derived class, in which it
 * *		  inherits from the Space class. There are two forests in the Island Escape game.
 * *		  This space contains essential items to construct the boat.
 * ************************************************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Space.hpp"

#include <string>
#include <vector>

class Forest : public Space{
	public:
		Forest(std::string spaceName) : Space(spaceName){}

		void spaceDescription();
		void spaceInteraction(std::vector<std::string>& backpack, int capacity);
};

#endif

