#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ant;  // Forward declaration

class Room {
private:
    string name;
    int capacity;
    vector<Room*> connections;
    vector<Ant*> ants;

public:
    Room(string name, int capacity);
    ~Room();

    string getName() const { return name; }
    int getCapacity() const { return capacity; }
    void setCapacity(int newCapacity) { capacity = newCapacity; }
    void addConnection(Room* room);
    vector<Room*> getConnections() const { return connections; }
    
    void addAnt(Ant* ant);
    void removeAnt(Ant* ant);
};

#endif
