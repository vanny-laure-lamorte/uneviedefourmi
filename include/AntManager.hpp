#ifndef ANTMANAGER_HPP
#define ANTMANAGER_HPP

#include "Ant.hpp"
#include "Room.hpp"
#include "PathFinder.hpp"
#include <algorithm>

#include <vector>
#include <memory>

class AntManager {
public:
    AntManager(std::vector<Ant>& ants, std::shared_ptr<Room> start, std::shared_ptr<Room> end);

    void assignPaths();
    void moveAntsStepByStep();

private:
    std::vector<Ant>& ants;
    std::shared_ptr<Room> startRoom;
    std::shared_ptr<Room> endRoom;
    PathFinder pathFinder;

    bool canMoveToRoom(std::shared_ptr<Room> room) const;
    int getAntsInRoom(std::shared_ptr<Room> room) const;
};

#endif
