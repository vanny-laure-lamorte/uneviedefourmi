#include "PathFinder.hpp"
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>

std::vector<std::shared_ptr<Room>> PathFinder::findShortestPath(std::shared_ptr<Room> start, std::shared_ptr<Room> end) {
    std::unordered_map<std::shared_ptr<Room>, std::shared_ptr<Room>> cameFrom;
    std::queue<std::shared_ptr<Room>> toVisit;
    std::set<std::shared_ptr<Room>> visited;

    toVisit.push(start);
    visited.insert(start);

    while (!toVisit.empty()) {
        auto current = toVisit.front();
        toVisit.pop();

        if (current == end)
            break;

        for (auto& neighbor : current->getTunnels()) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                cameFrom[neighbor] = current;
                toVisit.push(neighbor);
            }
        }
    }

    std::vector<std::shared_ptr<Room>> path;
    if (cameFrom.find(end) == cameFrom.end()) {
        return path;  // no path found
    }

    for (auto at = end; at != nullptr; at = cameFrom[at]) {
        path.push_back(at);
    }

    std::reverse(path.begin(), path.end());
    return path;
}
