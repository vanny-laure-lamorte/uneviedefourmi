#include "Ant.hpp"

Ant::Ant(int id, Room* startingRoom) : id(id), currentRoom(startingRoom) {

}
void Ant::moveAntToNewLocation(Room* targetRoom) {
    currentRoom = targetRoom;
}

int Ant::getId(){
    return id;
}

Room* Ant::getStartRoom(){
    return currentRoom;
}

string Ant::getCurrentRoomName(){
    return currentRoom->getName();
}
