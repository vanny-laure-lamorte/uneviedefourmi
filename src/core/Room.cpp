#include "Room.hpp"
#include "Ant.hpp"
#include <algorithm>

Room::Room(string name, int capacity) : name(name), capacity(capacity)
{
    cout << "Room constructor: " << name << endl;
}

Room::~Room() {}

void Room::addConnection(Room* room)
{
    if (find(connections.begin(), connections.end(), room) == connections.end())
    {
        connections.push_back(room);
        cout << "Connected " << name << " with " << room->getName() << endl;
    }
}

void Room::addAnt(Ant* ant)
{
    ants.push_back(ant);
    capacity--;
}

void Room::removeAnt(Ant* ant)
{
    ants.erase(remove(ants.begin(), ants.end(), ant), ants.end());
    capacity++;
}
