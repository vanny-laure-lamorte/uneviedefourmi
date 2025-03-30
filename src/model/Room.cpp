#include "Room.hpp"

void Room::addTunnels(Room* room)
{
    tunnels.push_back(room);
    cout << "Debug: Tunnel added from " << name << " to " << room->getName() << endl;
}

string Room::getName(){
    return name;
}

int Room::getCapacity(){
    return capacity;
}

int Room::getCurrentOccupants() {
    return currentOccupant;
}

void Room::addAnt() {
    if (capacity == -1 || currentOccupant < capacity) {
        currentOccupant++;
        cout << "Ant entered room " << name << ". Current occupants: " << currentOccupant << endl;
    } else {
        cout << "Room " << name << " is full. Cannot add more ants." << endl;
    }
}

void Room::removeAnt() {
    if (currentOccupant > 0) {
        currentOccupant--;
        cout << "Ant left room " << name << ". Current occupants: " << currentOccupant << endl;
    } else {
        cout << "No ants to remove from room " << name << "." << endl;
    }
}

vector<string> Room::getTunnelsName(){
    vector<string> tunnelNames;
    for (auto& tunnel : tunnels) {
        tunnelNames.push_back(tunnel->getName());
    }

    cout << "Tunnels for " << name << ": ";
    for (const auto& tunnelName : tunnelNames) {
        cout << tunnelName << " ";
    }
    cout << endl;
    return tunnelNames;
}
