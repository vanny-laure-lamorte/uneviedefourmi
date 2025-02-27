#include "Ant.hpp"

void Ant::moveAntToNewLocation(Room* targetRoom) {
    currentRoom = targetRoom;
}

int Ant::getId(){
    return id;
}

Room* Ant::getStartRoom(){
    return currentRoom;
}

