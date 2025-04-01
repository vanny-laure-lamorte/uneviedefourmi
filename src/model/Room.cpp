#include "Room.hpp"

Room::Room(const std::string& name, int capacity)
    : name(name), capacity(capacity) {}

const std::string& Room::getName() const {
    return name;
}

int Room::getCapacity() const {
    return capacity;
}

void Room::addTunnel(std::shared_ptr<Room> room) {
    tunnels.push_back(room);
}

const std::vector<std::shared_ptr<Room>>& Room::getTunnels() const {
    return tunnels;
}
