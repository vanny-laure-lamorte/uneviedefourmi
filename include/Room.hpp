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
    vector<Room*> tunnels;

    Room(const string& roomName, int roomCapacity) 
        : name(roomName), capacity(roomCapacity) {}
    
    /**
     * @brief
     */

    void addTunnels(Room* room); 

    // Info Room
    string getName(); 
    int getCapacity();
    vector<Room*> getTunnels();

private:
   
};

#endif // ROOM_HPP