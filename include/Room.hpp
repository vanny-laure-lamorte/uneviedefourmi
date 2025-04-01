#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
#include <vector>
#include <memory>
#include "InputValidator.hpp"

class Room {
    public:
        Room(const std::string& name, int capacity);

    /**
     * @brief Add tunnels to the room
     * @param Room* room
     */
    void addTunnel(std::shared_ptr<Room> room);

    /**
     * @brief Get the name of the room
     * @return string name
     */
    const std::string& getName() const;

    /**
     * @brief Get the capacity of the room
     * @return int capacity
     */
    int getCapacity() const;

    /**
     * @brief Get the tunnels of the room
     * @return vector<Room*> tunnels
     */
    const std::vector<std::shared_ptr<Room>>& getTunnels() const;

    private:
    std::string name;
    int capacity;
    std::vector<std::shared_ptr<Room>> tunnels;
};

#endif // ROOM_HPP