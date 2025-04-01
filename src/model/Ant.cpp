#include "Ant.hpp"

Ant::Ant(int id, std::shared_ptr<Room> startRoom)
    : id(id), currentRoom(startRoom) {}

void Ant::moveTo(std::shared_ptr<Room> targetRoom) {
    currentRoom = targetRoom;
}

int Ant::getId() const {
    return id;
}

std::shared_ptr<Room> Ant::getCurrentRoom() const {
    return currentRoom;
}

void Ant::setPath(const std::vector<std::shared_ptr<Room>>& path) {
    pathToDestination = path;
    currentPathIndex = 0;
}

std::vector<std::shared_ptr<Room>>& Ant::getPath() {
    return pathToDestination;
}

size_t Ant::getCurrentIndex() const {
    return currentPathIndex;
}

void Ant::incrementIndex() {
    currentPathIndex++;
}
