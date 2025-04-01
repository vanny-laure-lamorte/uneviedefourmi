#include "DataManager.hpp"
#include <memory>

std::vector<std::filesystem::path> DataManager::scanFilesInJson() {
    std::vector<std::filesystem::path> files;
    for (const auto& entry : std::filesystem::directory_iterator(
             std::filesystem::current_path().parent_path().string() + "\\assets\\json")) {
        files.push_back(entry.path());
    }
    return files;
}

json DataManager::getAnthillData(int anthillNumber) {
    std::string filePath = scanFilesInJson()[0].string();
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening the JSON file.\n";
        return json();
    }

    json data;
    file >> data;

    for (const auto& anthill : data) {
        if (anthill["anthill"] == anthillNumber) {
            std::cout << "Matching anthill found:\n" << anthill.dump(4) << std::endl;
            return anthill;
        }
    }
    return data;
}

Anthill DataManager::loadAnthillFromJson(int anthillNumber) {
    try {
        json anthillData = getAnthillData(anthillNumber);
        if (anthillData.is_null()) {
            throw std::runtime_error("Anthill data is empty or invalid.");
        }

        std::vector<std::shared_ptr<Room>> rooms;
        std::shared_ptr<Room> vestibule = nullptr;
        std::shared_ptr<Room> dortoir = nullptr;

        for (const auto& [roomName, capacity] : anthillData["rooms"].items()) {
            auto newRoom = std::make_shared<Room>(roomName, capacity);
            rooms.push_back(newRoom);

            if (roomName == "SV") vestibule = newRoom;
            else if (roomName == "SD") dortoir = newRoom;
        }

        if (!vestibule || !dortoir) {
            throw std::runtime_error("Missing essential rooms (SV or SD).");
        }

        for (const auto& connection : anthillData["connections"]) {
            std::string from = connection["from"];
            std::string to = connection["to"];

            std::shared_ptr<Room> fromRoom = nullptr;
            std::shared_ptr<Room> toRoom = nullptr;

            for (auto& room : rooms) {
                if (room->getName() == from) fromRoom = room;
                if (room->getName() == to) toRoom = room;
            }

            if (fromRoom && toRoom) {
                fromRoom->addTunnel(toRoom);
                std::cout << "[DEBUG] Tunnel: " << fromRoom->getName()
                          << " -> " << toRoom->getName() << std::endl;
            }
        }

        std::vector<Ant> ants;
        int numberOfAnts = anthillData["ants"];
        for (int i = 1; i <= numberOfAnts; i++) {
            ants.emplace_back(i, vestibule);
        }

        return Anthill(rooms, ants, vestibule, dortoir, 0);
    } catch (const std::exception& e) {
        std::cerr << "Error loading anthill: " << e.what() << std::endl;
        return Anthill({}, {}, nullptr, nullptr, 0);
    }
}
