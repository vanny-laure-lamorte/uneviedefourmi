#ifndef TERMINALDISPLAY_HPP
#define TERMINALDISPLAY_HPP

#include "InputValidator.hpp"

#include <iostream>
#include <vector>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class TerminalDisplay
{
public:

    /**
     * @brief Displays anthill info according to the user's choice from the anthill menu
     */
    void displayAnthillRoomInfo(string roomName, int capacity, vector<string> tunnelNames);
    void displayAnthillAntInfo(string antName, int id, string currentRoom);

    /**
     * @brief Displays anthill info according to the user's choice from the anthill menu
     */
    void displayAnthillInfo(int anthillNumber);
    
private:
};

#endif // TERMINALDISPLAY_HPP