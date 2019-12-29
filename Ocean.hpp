/**************************************************************************************************
 * * Program name: Ocean.hpp
 * * Author: Julian Torres
 * * Date: 07 December 2019
 * * Description: This is the header file of the Ocean class. This is a derived class, in which it
 * *		  inherits from the Space class. As the game takes place on an island, the Ocean
 * *		  space is linked to every other space. This is the last space a player will need
 * *		  to access; however, the player is unable to access this space until a boat is
 * *		  constructed.
 * ************************************************************************************************/

#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "Space.hpp"

#include <string>
#include <vector>

class Ocean : public Space{
	public:
		Ocean(std::string spaceName) : Space(spaceName){}

		void spaceDescription();
		void spaceInteraction(std::vector<std::string>& backpack, int capacity);
};

#endif

