#include "Room.hpp"

void Room::addTunnels(Room* room)
{
    tunnels.push_back(room);
}

string Room::getName(){
    return name;
}

int Room::getCapacity(){
    return capacity;
}

vector<Room*> Room::getTunnels(){
    return tunnels; 
}

vector<string> Room::getTunnelsName(){
    vector<string> tunnelNames;
    for (auto& tunnel : tunnels) {
        tunnelNames.push_back(tunnel->getName());
    }
    return tunnelNames; 
}