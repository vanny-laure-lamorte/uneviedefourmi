#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include "InputValidator.hpp"
#include "Room.hpp"
#include "Ant.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
using namespace std;

class Anthill
{
public:
    

        Anthill(const std::vector<std::shared_ptr<Room>>& roomsList, 
            const std::vector<Ant>& antsList, 
            std::shared_ptr<Room> Sv, 
            std::shared_ptr<Room> Sd, 
            int step);

    void moveAntsWithManager();

    std::shared_ptr<Room> findRoomByName(const std::string& roomName);

    /** 
     * @brief Displays the current positions of the ants in the anthill
     * When the user presses Enter, the ants move to the next room
    */
    void displayAntLocationStepByStep();
    
    /** 
     * @brief Displays all info related to the anthill choosen
     * number of rooms, number of ants, etc.
    */
    void displayAnthillInfo() const;

    bool isValid() const;

private:
vector<shared_ptr<Room>> anthillRoomsList;
vector<Ant> anthillAntsList;
shared_ptr<Room> Sv;
shared_ptr<Room> Sd;
int step;

bool canMoveToRoom(const std::shared_ptr<Room>& room) const;
int getAntsInRoom(const std::shared_ptr<Room>& room) const;
};

#endif // ANTHILL_HPP
