#include "Ant.hpp"

void Ant::moveAntToNewLocation(Room* targetRoom) {
    currentRoom = targetRoom;
    cout << "Ant " << id << " moved to room " << currentRoom->getName()<< endl;
}

int Ant::getId(){
    return id;
}

Room* Ant::getStartRoom(){
    return currentRoom;
}