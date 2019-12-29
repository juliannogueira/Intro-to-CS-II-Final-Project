/**************************************************************************************************
 * * Program name: Space.hpp
 * * Author: Julian Torres
 * * Date: 05 December 2019
 * * Description: This is the header file for the Space class. This is an abstract class that
 * *		  contains pointers to Space class objects, and functions to link the spaces,
 * *		  thereby creating a map.
 * ************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <vector>

class Space{
	protected:
		Space* northSpace;
	        Space* eastSpace;
	        Space* southSpace;
	        Space* westSpace;

		std::string spaceName,
			    menuOption;

		std::vector<std::string> spaceItems;

	public:
		// The constructor assigns the linked pointers null values
		Space(std::string spaceName){
			this->spaceName = spaceName;
			northSpace = nullptr;
			eastSpace = nullptr;
			southSpace = nullptr;
			westSpace = nullptr;
		}

		Space* getNorthSpace() const{ return northSpace; }
		Space* getEastSpace() const{ return eastSpace; }
		Space* getSouthSpace() const{ return southSpace; }
		Space* getWestSpace() const{ return westSpace; }

		std::string getNorthSpaceName() const{ return northSpace->spaceName; }
		std::string getEastSpaceName() const{ return eastSpace->spaceName; }
		std::string getSouthSpaceName() const{ return southSpace->spaceName; }
		std::string getWestSpaceName() const{ return westSpace->spaceName; }

		std::string getSpaceName() const{ return spaceName; }

		// Link the pointers to the object that calls the function
		void addSpace(Space* northSpace, Space* eastSpace,
			      Space* southSpace, Space* westSpace){
			this->northSpace = northSpace;
			this->eastSpace = eastSpace;
			this->southSpace = southSpace;
			this->westSpace = westSpace;
		}

		// Add items to specific space
		void addSpaceItems(std::string item){ spaceItems.push_back(item); }

		// Pure virtual functions are defined in each derived class
		virtual void spaceDescription()=0;
		virtual void spaceInteraction(std::vector<std::string>& backpack, int capacity)=0;

};

#endif

