#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include "InputValidator.hpp"
#include "MainMenu.ui.hpp"
#include "Room.hpp"
#include "Ant.hpp"
#include "DataManager.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Anthill
{
public:

    DataManager dataManager;
    MainMenu mainMenu;
    
    vector<Room> rooms;
    vector<Ant> ants;
    Room *Sv;
    Room *Sd;
    int step = 1;

    Anthill(json anthillData);

    void moveAnts();

    /** 
     * @brief Displays the current positions of the ants in the anthill
     * When the user presses Enter, the ants move to the next room
    */
    void displayAntLocationStepByStep();
    
    /** 
     * @brief Displays all info related to the anthill choosen
     * number of rooms, number of ants, etc.
    */
    void displayAnthillInfo();

private:
    
    Room *findRoomByName(const string &roomName);
    bool canMoveToRoom(Room *room);
    int getAntsInRoom(Room *room);
};

#endif // ANTHILL_HPP
