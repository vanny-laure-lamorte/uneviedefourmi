#include "AntManager.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

AntManager::AntManager(std::vector<Ant>& ants, std::shared_ptr<Room> start, std::shared_ptr<Room> end)
    : ants(ants), startRoom(start), endRoom(end) {}

void AntManager::assignPaths() {
    for (auto& ant : ants) {
        auto path = pathFinder.findShortestPath(startRoom, endRoom);
        ant.setPath(path);
    }
}

bool AntManager::canMoveToRoom(std::shared_ptr<Room> room) const {
    return room->getCapacity() == -1 || getAntsInRoom(room) < room->getCapacity();
}

int AntManager::getAntsInRoom(std::shared_ptr<Room> room) const {
    int count = 0;
    for (const auto& ant : ants) {
        if (ant.getCurrentRoom() == room) {
            count++;
        }
    }
    return count;
}

void AntManager::moveAntsStepByStep() {
    int step = 1;
    while (true) {
        std::cout << "\n=== STEP " << step << " ===" << std::endl;

        for (const auto& ant : ants) {
            std::cout << "Ant " << ant.getId() << " is in room " << ant.getCurrentRoom()->getName() << std::endl;
        }

        std::cout << "\nPress Enter to move ants...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool allReached = true;

        for (auto& ant : ants) {
            if (ant.getCurrentRoom() == endRoom)
                continue;

            bool moved = false;
            auto& path = ant.getPath();

            if (ant.getCurrentIndex() + 1 < path.size()) {
                auto nextRoom = path[ant.getCurrentIndex() + 1];

                if (canMoveToRoom(nextRoom)) {
                    ant.moveTo(nextRoom);
                    ant.incrementIndex();
                    std::cout << "Ant " << ant.getId() << " moved to room " << nextRoom->getName() << std::endl;
                    moved = true;
                }
            }

            if (!moved) {
                auto currentRoom = ant.getCurrentRoom();

                for (const auto& neighbor : currentRoom->getTunnels()) {
                    if (!canMoveToRoom(neighbor))
                        continue;

                    auto testPath = pathFinder.findShortestPath(neighbor, endRoom);
                    if (!testPath.empty()) {
                        // Build full path: currentRoom → neighbor → ... → endRoom
                        testPath.insert(testPath.begin(), currentRoom);
                        ant.setPath(testPath);
                        ant.moveTo(neighbor);
                        ant.incrementIndex();
                        std::cout << "Ant " << ant.getId() << " rerouted via " << neighbor->getName() << std::endl;
                        moved = true;
                        break;
                    }
                }
            }

            if (!moved) {
                std::cout << "Ant " << ant.getId() << " couldn't move (no available path)." << std::endl;
                allReached = false;
            }
        }

        allReached = std::all_of(ants.begin(), ants.end(), [this](const Ant& ant) {
            return ant.getCurrentRoom() == endRoom;
        });

        if (allReached) {
            std::cout << "\n✅ All ants have reached the end room!" << std::endl;
            break;
        }

        step++;
    }
}
