#ifndef ROOM_HPP
#define ROOM_HPP
#include "Ant.hpp"

using namespace std;
#include <vector>
#include <algorithm>

class Room
{
private:
    string name;
    int capacity;
    vector<Room *> connections;
    vector<Ant *> ants;

public:
    /**
     * @brief Constructor
     * @param name The name of the room
     * @param capacity The capacity of the room
     */
    Room(string name, int capacity);
    ~Room();

    /**
     * @brief Get the name of the room
     * @return string The name of the room
     */
    string getName() const { return name; }

    /**
     * @brief Get the capacity of the room
     * @return int The capacity of the room
     */
    int getCapacity() const { return capacity; }

    /**
     * @brief Set the capacity of the room
     * @param newCapacity The new capacity of the room
     */
    void setCapacity(int newCapacity) { capacity = newCapacity; }

    /**
     * @brief Add a connection to the room
     * @param room The room to connect to
     */
    void addConnection(Room *room);

    /**
     * @brief Get the connections of the room
     * @return vector<Room*> The connections of the room
     */
    vector<Room *> getConnections() const { return connections; }

    /**
     * @brief Add an ant to the room
     * @param ant The ant to add
     */
    void addAnt(Ant *ant);

    /**
     * @brief Remove an ant from the room
     * @param ant The ant to remove
     */
    void removeAnt(Ant *ant);
};

#endif