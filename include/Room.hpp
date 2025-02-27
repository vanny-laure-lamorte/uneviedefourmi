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
    vector<Room *> tunnels;

    Room(const string &roomName, int roomCapacity)
        : name(roomName), capacity(roomCapacity) {}

    /**
     * @brief Add tunnels to the room
     * @param Room* room
     */
    void addTunnels(Room *room);

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

    /**
     * @brief Get the tunnels of the room
     * @return vector<Room*> tunnels
     */
    vector<Room *> getTunnels();

private:
};

#endif // ROOM_HPP