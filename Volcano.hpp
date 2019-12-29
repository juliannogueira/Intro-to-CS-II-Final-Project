/**************************************************************************************************
 * * Program name: Volcano.hpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the header file of the Volcano class. This is a derived class, in which
 * *		  it inherits from the Space class. There are two Volcano objects in the game. Both
 * *		  provide a risk to the player, where items may be removed from the backpack.
 * ************************************************************************************************/

#ifndef VOLCANO_HPP
#define VOLCANO_HPP

#include "Space.hpp"

#include <string>
#include <vector>

class Volcano : public Space{
	public:
		Volcano(std::string spaceName) : Space(spaceName){}

		void spaceDescription();
		void spaceInteraction(std::vector<std::string>& backpack, int capacity);
};

#endif

