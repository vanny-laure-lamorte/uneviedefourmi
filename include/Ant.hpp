#ifndef ANT_HPP
#define ANT_HPP

#include "Room.hpp"
#include <memory>
#include <vector>

class Ant {

public:
    Ant(int id, std::shared_ptr<Room> startRoom);

    void moveTo(std::shared_ptr<Room> targetRoom);
    int getId() const;
    std::shared_ptr<Room> getCurrentRoom() const;

    void setPath(const std::vector<std::shared_ptr<Room>>& path);
    std::vector<std::shared_ptr<Room>>& getPath();
    size_t getCurrentIndex() const;
    void incrementIndex();

private:
    int id;
    std::vector<std::shared_ptr<Room>> pathToDestination;
    std::shared_ptr<Room> currentRoom;
    size_t currentPathIndex = 0;
};

#endif
