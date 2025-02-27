#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "InputValidator.hpp"
#include "DataManager.hpp"
#include "DataManager.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class MainMenu
{
public:  

    int anthillMenuChoiceUser;
    InputValidator inputValidator;
    
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
     * @brief Handles the user's choice from the anthill menu and performs actions.
     * @param anthillMenuChoiceUser The user's choice from the anthill menu
     */
    void handleAnthillChoice(int anthillMenuChoiceUser);

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
    void handleAlgorithmChoice(int anthillAlgoritmChoiceUser);

    /**
     * @brief Displays a rectangle with a title inside, centered.
     * @param text The title to display inside the rectangle.
     * @param number The number to display inside the rectangle.
     */
    void displayRectangleWithTitleAndVariable(string text, int number);
    void displayRectangleWithTitle(string text);    

    /**
    * @brief Clears the console screen.
    */
    void clearScreen (){ printf("\033c");}

private:
   
};

#endif // MAINMENU_HPP