#ifndef ANT_HPP
#define ANT_HPP

#include "InputValidator.hpp"
#include "Room.hpp"

#include <iostream>
using namespace std;

class Ant
{
public:   

    int id;
    Room* currentRoom;

    Ant() : id(0), currentRoom(nullptr) {};
    Ant(int id, Room* startingRoom) : id(id), currentRoom(startingRoom) {}

    void moveAntToNewLocation(Room* targetRoom);

    int getId();
    Room* getStartRoom();

    string getCurrentRoomName();

private:
   
};

#endif // ANT_HPP
