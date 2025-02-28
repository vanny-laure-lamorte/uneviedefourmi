#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include "InputValidator.hpp"
#include "Room.hpp"
#include "Ant.hpp"
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
    
    vector<Room> anthillRoomsList;
    vector<Ant> anthillAntsList;
    Room *Sv;
    Room *Sd;
    int step = 0;

    Anthill(const vector<Room> &roomsList, const vector<Ant> &antsList, 
        const Room *Sv, const Room *Sd, int step);

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
