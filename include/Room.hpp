#ifndef ROOM_HPP
#define ROOM_HPP
#include "InputValidator.hpp"

#include <iostream>
#include <vector>
using namespace std;

class Room
{
public:

    string name;
    int capacity;
    int currentAntCount;
    vector<Room*> tunnels;

    Room(const string& roomName, int roomCapacity)
        : name(roomName), capacity(roomCapacity) {
        }

    /**
     * @brief Add tunnels to the room
     * @param Room* room
     */
   void addTunnels(Room* room);

    /**
     * @brief Get the name of the room
     * @return string name
     */
    string getName();

    /**
     * @brief Get the capacity of the room
     * @return int capacity
     */
    int getCapacity();

    int getCurrentOccupants();
    int currentOccupant;
    void addAnt();
    void removeAnt();

     /**
     * @brief Add a tunnel -connection to the room
     * @param room The room to which this room will be connected
     */
    vector<string> getTunnelsName();

private:

};

#endif // ROOM_HPP