/**************************************************************************************************
 * * Program name: menu.cpp
 * * Author: Julian Torres
 * * Date: 08 December 2019
 * * Description: This is the implementation file for the menu function. This is used in
 * * 		  conjunction with the Gameplay class.
 * ************************************************************************************************/

#include "Gameplay.hpp"

#include <iostream>
#include <string>

/**************************************************************************************************
 * * void Gameplay::menu()
 * * Description: This is the main menu of the program, prompting the user to play the game or quit
 * *              the program.
 * ************************************************************************************************/
void menu(){
	std::string option;

	bool gameStatus = true;

	while(gameStatus){
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl << "=================== Island Escape ====================";
		std::cout << std::endl << "======================================================";
		std::cout << std::endl;
		std::cout << std::endl << "1) Play";
		std::cout << std::endl << "2) Quit program";
		std::cout << std::endl;
		std::cout << std::endl << "Please enter a valid menu option: ";
		getline(std::cin, option);

		while(option != "1" && option != "2"){
			std::cout << std::endl << "Please enter a valid menu option: ";
			getline(std::cin, option);
		}

		// The user chose to play the game
		if(option == "1"){
			Gameplay gameplay; // Create the Gameplay object

			gameplay.gameDescription();

			// Run the following functions until the game has ended
			while(gameplay.getGameStatus()){
				gameplay.checkBackpack(); // Check if the capacity was reached
				gameplay.movePlayer();

				// The previous function could result in a change of status
				if(gameplay.getGameStatus()){
					gameplay.displayBackpack();
					gameplay.endOfDay();
				}
			}

			// After the game ends, prompt the user to play again before breaking the
			// outer while loop.
			gameStatus = true;
		}

		// The user chose to quit the program
		else{
			std::cout << std::endl << "Program terminating...";
			std::cout << std::endl;

			gameStatus = false;
		}
	}
}

