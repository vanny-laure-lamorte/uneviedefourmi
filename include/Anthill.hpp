#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include "InputValidator.hpp"
#include "MainMenu.ui.hpp"
#include "Room.hpp"
#include "Ant.hpp"
#include "DataManager.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Anthill
{
public:

    DataManager dataManager;
    MainMenu mainMenu;
    
    vector<Room> rooms;
    vector<Ant> ants;
    Room *Sv;
    Room *Sd;
    int step =1;

    Anthill(json anthillData);

    void moveAnts();

    /** 
     * Displays the current positions of all the ants
     * 
    */
    void displayAntLocationStepByStep();

    void displayAnthillInfo();



private:
    // Finds and returns a room pointer by its name
    Room *findRoomByName(const string &roomName);

    // Checks if an ant can move to a given room based on the room's capacity
    bool canMoveToRoom(Room *room);

    // Counts the number of ants in a given room
    int getAntsInRoom(Room *room);
};

#endif // ANTHILL_HPP
