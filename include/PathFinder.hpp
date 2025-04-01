#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "Room.hpp"

class PathFinder {
public:
    std::vector<std::shared_ptr<Room>> findShortestPath(std::shared_ptr<Room> start, std::shared_ptr<Room> end);
};

#endif
