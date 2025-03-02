#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "InputValidator.hpp"
#include "DataManager.hpp"
#include "UIRenderer.hpp"
#include "Anthill.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class MainMenu
{
public:  

    InputValidator inputValidator;  
    DataManager dataManager;

    int anthillMenuChoiceUser;
    int algorithmChoiceUser;
    
    /**
     * @brief Displays the welcome message and enters a loop where it displays the anthill menu and handles the user's 
     * selection until they choose to quit.
     */
    void mainMenu();

    /**
     * @brief Displays the welcome message of the program. The user has to press Enter to continue.
     */
    void displayWelcomeMessage();
    
    /**
     * @brief Displays the anthill menu and ask the user to select an option.
     * It validates the user's input to ensure it's a valid menu option.
     * @return int - The user's menu choice 
     */
    int displayAnthillMenu();    


    /**
     * @brief Displays the algorithm menu and ask the user to select an option.
     * It validates the user's input to ensure it's a valid menu option.
     * @return int - The user's menu choice.
     */
    int displayMenuChooseAlgorithm();

    /**
     * @brief Handles the user's choice from the algorithm menu and performs actions.
     * @param anthillAlgoritmChoiceUser The user's choice from the anthill menu.
     */
    void handleAlgorithmChoice(int anthillMenuChoiceUser, int anthillAlgoritmChoiceUser);


private:
   
};

#endif // MAINMENU_HPP