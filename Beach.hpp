/**************************************************************************************************
 * * Program name: Beach.hpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the header file of the Beach class. This is a derived class, in which it
 * *		  inherits from the Space class. There are a total of four beaches in Island Escape
 * *		  game.
 * ************************************************************************************************/

#ifndef BEACH_HPP
#define BEACH_HPP

#include "Space.hpp"

#include <string>
#include <vector>

class Beach : public Space{
	public:
		Beach(std::string spaceName) : Space(spaceName){}

		void spaceDescription();
		void spaceInteraction(std::vector<std::string>& backpack, int capacity);
};

#endif

